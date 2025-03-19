import numpy as np
import LoveWave

def get_reference_velocity(structure: np.ndarray[float], omegas: np.ndarray[float]) -> np.ndarray[float]:
    """
    Given a structure and an array of target angular frequencies,
    return the corresponding reference phase velocity array C_ref.
    """
    wave = LoveWave.LoveWave(0, structure)
    omega_model, c_model = wave.frequency()
    
    c_theoretical = []
    for omega in omegas:
        idx = np.argmin(np.abs(omega_model - omega))
        c_theoretical.append(c_model[idx])
    return np.array(c_theoretical)


def inversion(structure: np.ndarray[float], 
              C_ref: np.ndarray[float], 
              c_observed: np.ndarray[float], 
              delta: tuple[float], 
              omega: np.ndarray[float]) -> np.ndarray[float]:
    """
    structure: Structure parameters (including V1, V2)
    C_ref    : Reference phase velocities (from get_reference_velocity)
    C_obs    : Observed phase velocities
    delta    : [delV1, delV2] used for finite difference
    omega    : Array of angular frequencies
    """
    m_ref = np.array([structure[1], structure[3]])
    delV1, delV2 = delta

    d = np.array(c_observed) - np.array(C_ref)
    G = np.zeros([len(omega), 2])
    
    structure[1] = m_ref[0]
    structure[3] = m_ref[1]

    structure[1] += delV1
    
    love_wave = LoveWave.LoveWave(0, structure)
    w_m1, c1 = love_wave.frequency()
    
    for i in range(len(omega)):
        w = omega[i]
        idx = np.argmin(np.abs(w_m1 - w))
        G[i, 0] = (c1[idx] - C_ref[i]) / delV1
    
    structure[1] = m_ref[0]
    structure[3] = m_ref[1]

    structure[3] += delV2
    
    wave2 = LoveWave.LoveWave(0, structure)
    w_m2, c2 = wave2.frequency()
    
    for i in range(len(omega)):
        w = omega[i]
        idx = np.argmin(np.abs(w_m2 - w))
        G[i, 1] = (c2[idx] - C_ref[i]) / delV2

    delta_m, residuals, rank, s = np.linalg.lstsq(G, d, rcond=None)
    m_new = m_ref + delta_m
    
    return m_new