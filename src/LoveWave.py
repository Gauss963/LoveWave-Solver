import numpy as np
import matplotlib.pyplot as plt

class LoveWave():
    def __init__(self, n, structure):
        
        # shallow structure
        self.H  = structure[0]                           # thickness(m) 
        self.b1 = structure[1]                           # velocity (m/s)
        self.d1 = structure[2]                           # density  (kg*m^-3)
        self.u1 = self.b1**2*self.d1                     # shear modulus
        
        # deep background
        self.b2 = structure[3]                           # velocity (m/s)
        self.d2 = structure[4]                           # density  (kg*m^-3)
        self.u2 = self.b2**2*self.d2                     # shear modulus
        
        # model parameter
        self.n    = n                                    # nth overtone
        self.intv = 1/(10+abs(0.3-n)**2)                 # calculating step
        self.num  = int((self.b2-self.b1)/self.intv+1)   # calculating times
        
        # modeling
        self.c = np.linspace(self.b1, self.b2, self.num) # phase velocity
    
    def overtone(self, w, plot: bool = True) -> None:
        dv1 = np.sqrt(self.b1**(-2) - self.c**(-2))
        dv1[dv1==0.0] = 10**-16
        dv2 = np.sqrt(self.c**(-2)  - self.b2**(-2))
        w_y = dv1*self.H*w
        RHS = (dv2*self.u2)/(dv1*self.u1)
        LHS = np.tan(w_y)
        
        # numerical solution
        fi = []
        x  = []
        y  = []
        for i in range(1,self.c.shape[0]):
            aa = (RHS[i-1]-LHS[i-1])*(RHS[i]-LHS[i])
            if aa <= 0:
                fi.append(i)
        for i in range(len(fi)//2):
            j = np.where(w_y == w_y[fi[2*i]])[0][0]
            x.append(w_y[j])
            y.append(RHS[j])
            print(f'{i} overtune: {x[i].round(3)}, {y[i].round(3)}')
        if plot==True:            
            LHS[:-1][np.diff(LHS) < 0] = np.nan
            plt.plot(w_y, LHS, 'b', label='LHS')        
            plt.plot(w_y, RHS, 'r', label='RHS')
            plt.scatter(x, y, c='g')
            for i in range(len(x)):
                plt.text(x[i]+0.1, y[i]+0.1, f'n={i}')
            plt.hlines(0.0, min(w_y), max(w_y), 'k')
            plt.xlim(min(w_y), max(w_y))
            plt.ylim(-5.0, 40.0)
            plt.title(f'ω = {w}')
            plt.legend(loc='upper right')
            plt.show()

        return None
        
    def frequency(self) -> tuple[np.ndarray, np.ndarray]:
        dv1 = np.sqrt(self.b1**(-2) - self.c**(-2))
        dv1[dv1==0.0] = 10**-16
        dv2 = np.sqrt(self.c**(-2)  - self.b2**(-2))
        # analytic solution
        w = np.arctan( (self.u2*dv2)/(self.u1*dv1) )
        w = (w + self.n*np.pi)/(self.H*dv1)
        return w, self.c

    def velocity(self, w):
        k = w/self.c
        n = self.c.shape[0]
        dc_dk = np.zeros([n])
        for i in range(1, n):
            dc_dk[i] = (self.c[i]-self.c[i-1])/(k[i]-k[i-1])
        U = self.c + k*dc_dk
        U[0] = self.c[0]
        return U, self.c