#include "utils.hh"
#include "LoveWave.hh"

#include <fstream>
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

        // std::cout << "pertub b1: " << std::endl; // See pertubation b1 reslut.
        // printVector(c_p);                        // See pertubation b1 reslut.

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

        // std::cout << "pertub b2: " << std::endl; // See pertubation b2 reslut.
        // printVector(c_p);                        // See pertubation b2 reslut.

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

std::vector<double> linspace(double start, double end, std::size_t num) {
    std::vector<double> result;
    result.reserve(num);
    if (num == 0) return result;
    if (num == 1) {
        result.push_back(start);
        return result;
    }

    double step = (end - start) / (num - 1);
    for (std::size_t i = 0; i < num; ++i) {
        result.push_back(start + step * i);
    }
    return result;
}

void saveVectorsToBinary(const std::vector<double>& frequencies_plot,
                         const std::vector<double>& cTheoretical_plot,
                         const std::string& filename) {
    std::ofstream out(filename, std::ios::binary);
    if (!out) {
        throw std::runtime_error("Cannot open file for writing: " + filename);
    }

    size_t size = frequencies_plot.size();
    out.write(reinterpret_cast<const char*>(&size), sizeof(size));

    out.write(reinterpret_cast<const char*>(frequencies_plot.data()), size * sizeof(double));
    out.write(reinterpret_cast<const char*>(cTheoretical_plot.data()), size * sizeof(double));

    out.close();
}

void printVector(const std::vector<double> &signal) {
    std::cout << "[ ";
    for(int ii = 0; ii < signal.size(); ii++) {
        std::cout << signal[ii] << ", ";
    }
    std::cout << "]" << std::endl;
}
