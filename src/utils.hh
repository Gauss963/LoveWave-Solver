#ifndef UTILS_HH
#define UTILS_HH

#include "LoveWave.hh"
#include <vector>

void saveVectorsToBinary(const std::vector<double>& frequencies_plot,
    const std::vector<double>& cTheoretical_plot,
    const std::string& filename);

std::vector<double> linspace(double start, double end, std::size_t num);

LoveWaveParams inversion(const LoveWaveParams& initParams,
                         const std::vector<double>& C_theory, // theory phase velocity
                         const std::vector<double>& C_obs,    // Observed phase velocity
                         double deltaV1,                      // Used to calculate dC/db1
                         double deltaV2,                      // Used to calculate dC/db2
                         const std::vector<double>& freq);
#endif // UTILS_HH