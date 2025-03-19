import numpy as np
import utils

def main():
    frequencies = np.array([0.08, 0.15, 0.18, 0.22])
    omega = 2 * np.pi * frequencies
    
    structure = np.array([
        10000.0, 
        3000.0,  
        2800.0,
        5000.0,
        3300.0
    ])

    c_observed = np.array([4130, 3529, 3427, 3346])
    c_theoretical = utils.get_reference_velocity(structure, omega)

    delta = (1.0, 1.0)

    print("\n== Theoretical dispersion == by Python")
    for i in range(len(frequencies)):
        print(f"f = {frequencies[i]:.2f} Hz => c_Theoretical = {c_theoretical[i]:.2f} m/s")
    m = utils.inversion(structure, c_theoretical, c_observed, delta, omega)

    print('\n== Inversion result ==')
    print(f'Updated b1 = {m[0]:.2f} m/s')
    print(f'Updated b2 = {m[1]:.2f} m/s')

if __name__ == "__main__":

    main()