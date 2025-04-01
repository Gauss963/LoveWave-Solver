#include "LoveWave.hh"
#include "utils.hh"
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

int main() {
    LoveWaveParams structure = {
        10000.0,
        3000.0,
        2800.0,
        5000.0,
        3200.0
    };

    // std::vector<double> frequencies  = { 0.08, 0.15, 0.18, 0.22 };
    std::vector<double> frequencies  = { 0.1, 0.2, 0.3, 0.4, 0.6 };
    // std::vector<double> cObserved = { 4130, 3529, 3427, 3346 };
    std::vector<double> cObserved = { 3721, 3191, 3087, 3050, 3023 };

    LoveWave lovaWave(structure);
    std::vector<double> frequencies_plot = linspace(0.01, .70, 8192);
    // std::vector<double> frequencies_plot = linspace(0.01, 1.60, 8192);
    std::vector<double> cTheoretical = lovaWave.getDispersion(frequencies);
    std::vector<double> cTheoretical_plot = lovaWave.getDispersion(frequencies_plot);
    saveVectorsToBinary(frequencies_plot, cTheoretical_plot, "../data/data.bin");

    std::cout << "\n== Theoretical dispersion == by C++\n";
    for (size_t i = 0; i < frequencies.size(); ++i) {
        std::cout << "f = " << frequencies[i]
                  << " Hz => c_Theoretical = " << cTheoretical[i] << " m/s\n";
    }


    double deltaV1 = 10.0;
    double deltaV2 = 10.0;

    // int iterNum = 100000;
    int iterNum = 1;
    std::vector<LoveWaveParams> newParams(iterNum);
    newParams[0] = inversion(structure, cTheoretical, cObserved,
                            deltaV1, deltaV2, frequencies);
    for (int ii = 1; ii < iterNum; ii++) {
        newParams[ii] = inversion(newParams[ii - 1], cTheoretical, cObserved,
                                deltaV1, deltaV2, frequencies);
    }

    std::cout << "\n== Inversion result ==\n";
    if (std::isnan(newParams.back().b1) || std::isnan(newParams.back().b2)) {
        std::cout << "Singular or invalid matrix, cannot invert.\n";
    } else {
        std::cout << "Updated b1 = " << newParams.back().b1 << " m/s\n";
        std::cout << "Updated b2 = " << newParams.back().b2 << " m/s\n";
    }

    std::cout << "\n== After Pertubation ==\n";
    LoveWave lovaWavePertub(newParams.back());
    for (size_t i = 0; i < frequencies.size(); ++i) {
        std::cout << "f = " << frequencies[i]
                  << " Hz => c_Theoretical_P = " << lovaWavePertub.getDispersion(frequencies)[i] << " m/s\n";
    }

    return 0;
}