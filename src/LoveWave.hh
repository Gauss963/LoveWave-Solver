#ifndef LOVEWAVE_HH
#define LOVEWAVE_HH

#include <vector>

struct LoveWaveParams {
    double H;   // Upper layer thickness
    double b1;  // Upper layer velocity
    double d1;  // Upper layer density
    double b2;  // Half-space velocity
    double d2;  // Half-space density
};

class LoveWave {
    public:
        explicit LoveWave(const LoveWaveParams& params);
        std::vector<double> getDispersion(const std::vector<double>& freq) const;

    private:
        double H_;
        double b1_, d1_;
        double b2_, d2_;
        double fLove(double c, double omega) const;
        double solveC(double omega, double tol = 1e-10, int max_iter = 4e8) const;
        double bisectionSearch(
            double left, 
            double right, 
            double fL, 
            double fR, 
            double omega, 
            double tol, 
            int max_iter) const;
};

#endif // LOVEWAVE_HH