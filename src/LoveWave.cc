#include "LoveWave.hh"
#include <iostream>
#include <cmath>
#include <limits>

LoveWave::LoveWave(const LoveWaveParams& params):
    H_(params.H),
    b1_(params.b1),
    d1_(params.d1),
    b2_(params.b2),
    d2_(params.d2) {}

double LoveWave::fLove(double c, double omega) const {
    
    double k = omega / c;
    double u1 = this->b1_ * this->b1_ * this->d1_;
    double u2 = this->b2_ * this->b2_ * this->d2_;

    double val1 = (omega * omega) / (this->b1_ * this->b1_) - k * k;
    double val2 = k * k - (omega * omega) / (this->b2_ * this->b2_);

    if (val1 <= 0.0 || val2 <= 0.0) {
        return std::numeric_limits<double>::quiet_NaN();
    }

    double alpha1 = std::sqrt(val1);
    double alpha2 = std::sqrt(val2);

    double lhs = std::tan(alpha1 * this->H_);
    double rhs = (alpha2 * u2) / (alpha1 * u1);

    return lhs - rhs;
}

double LoveWave::solveC(double omega, double tol, int max_iter) const {

    double scanLeft  = this->b1_ + 1.0;
    double scanRight = this->b2_ - 1.0;

    if (scanLeft >= scanRight) {
        return -1.0;
    }
    const int numSteps = 50;
    double step = (scanRight - scanLeft) / static_cast<double>(numSteps);

    double left = scanLeft;
    double fL   = fLove(left, omega);
    if (std::isnan(fL)) {
        fL = 1.0e10;
    }

    bool foundBracket = false;
    for (int i = 1; i <= numSteps; ++i) {
        double right = scanLeft + i * step;
        double fR = fLove(right, omega);
        if (std::isnan(fR)) {
            fR = 1.0e10;
        }
        if (fL * fR < 0.0) {
            foundBracket = true;
            double c = bisectionSearch(left, right, fL, fR, omega, tol, max_iter);
            return c;
        }
        left = right;
        fL   = fR;
    }
    return -1.0;
}

double LoveWave::bisectionSearch(
    double left, double right, 
    double fL, double fR,
    double omega, double tol, int max_iter) const {

    if (fL * fR > 0.0) {
        return -1.0;
    }

    double mid = 0.0;
    for (int iter = 0; iter < max_iter; ++iter) {
        mid = 0.5 * (left + right);
        double fM = fLove(mid, omega);

        if (std::isnan(fM)) {
            fM = fL; 
        }

        if (std::fabs(fM) < tol) {
            return mid;
        }
        if (fL * fM < 0.0) {
            right = mid;
            fR    = fM;
        } else {
            left  = mid;
            fL    = fM;
        }
        if (iter == max_iter - 1) {
            std::cerr << "LoveWave::bisectionSearch: Failed to converge, fM = "
                      << std::fabs(fM) << std::endl;
        }
    }
    return mid;
}

std::vector<double> LoveWave::getDispersion(const std::vector<double>& frequencies) const {
   
    std::vector<double> velocities(frequencies.size(), -1.0);
    for (size_t i = 0; i < frequencies.size(); ++i) {
        double omega = 2.0 * M_PI * frequencies[i];
        double velocity = solveC(omega);
        velocities[i] = velocity;
    }
    return velocities;
}