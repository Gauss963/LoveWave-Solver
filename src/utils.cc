#include "utils.hh"
#include "LoveWave.hh"

#include <Eigen/Dense>
#include <cmath>
#include <iostream>
#include <limits>

LoveWaveParams inversion(const LoveWaveParams& initParams,
                         const std::vector<double>& cTheoretical,
                         const std::vector<double>& cObserved,
                         double deltaV1,
                         double deltaV2,
                         const std::vector<double>& frequencies)
{
    if (cTheoretical.size() != cObserved.size() || cObserved.size() != frequencies.size()) {
        LoveWaveParams outParams;
        outParams.H  = std::numeric_limits<double>::quiet_NaN();
        outParams.b1 = std::numeric_limits<double>::quiet_NaN();
        outParams.d1 = std::numeric_limits<double>::quiet_NaN();
        outParams.b2 = std::numeric_limits<double>::quiet_NaN();
        outParams.d2 = std::numeric_limits<double>::quiet_NaN();
        return outParams;
    }

    double b1 = initParams.b1;
    double b2 = initParams.b2;

    size_t N = cObserved.size();

    Eigen::VectorXd dVec(N);
    for (size_t i = 0; i < N; ++i) {
        dVec(i) = cObserved[i] - cTheoretical[i];
    }

    Eigen::MatrixXd G(N, 2);
    G.setZero();

    // 1. Perturb b1 -> b1 + deltaV1
    {
        LoveWaveParams paramsPert = initParams;
        paramsPert.b1 = b1 + deltaV1;

        LoveWave lw_p(paramsPert);
        std::vector<double> c_p = lw_p.getDispersion(frequencies);

        for (size_t i = 0; i < N; ++i) {
            double diff = c_p[i] - cTheoretical[i];
            G(i, 0) = diff / deltaV1;
        }
    }

    // 2. Perturb b2 -> b2 + deltaV2
    {
        LoveWaveParams paramsPert = initParams;
        paramsPert.b2 = b2 + deltaV2;

        LoveWave lw_p(paramsPert);
        std::vector<double> c_p = lw_p.getDispersion(frequencies);

        for (size_t i = 0; i < N; ++i) {
            double diff = c_p[i] - cTheoretical[i];
            G(i, 1) = diff / deltaV2;
        }
    }

    Eigen::MatrixXd GTG = G.transpose() * G;
    double detVal = GTG.determinant();
    if (std::fabs(detVal) < 1e-14) {
        LoveWaveParams outParams;
        outParams.H  = std::numeric_limits<double>::quiet_NaN();
        outParams.b1 = std::numeric_limits<double>::quiet_NaN();
        outParams.d1 = std::numeric_limits<double>::quiet_NaN();
        outParams.b2 = std::numeric_limits<double>::quiet_NaN();
        outParams.d2 = std::numeric_limits<double>::quiet_NaN();
        return outParams;
    }

    Eigen::VectorXd m_perturb = GTG.inverse() * G.transpose() * dVec;

    double new_b1 = b1 + m_perturb(0);
    double new_b2 = b2 + m_perturb(1);

    // Update b1, b2
    LoveWaveParams outParams = initParams;
    outParams.b1 = new_b1;
    outParams.b2 = new_b2;
    
    return outParams;
}