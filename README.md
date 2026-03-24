# Love Wave Simulation

![Standard](https://img.shields.io/badge/Standard-C++23-indigo)
![Platform](https://img.shields.io/badge/Platform-win%E2%80%9464%20%7C%20MacOS%E2%80%94arm64%20%7C%20linux%E2%80%94aarch64%20%7C%20linux%E2%80%9464%20%7C%20MacOS%E2%80%9464-clelery)
![Compiler](https://img.shields.io/badge/Compiler-Apple_Clang_Tested-Red)
![License](https://img.shields.io/badge/License-MIT-blue)


This project implements a Love wave simulation using C++. It consists of multiple source files for wave modeling and utility functions.

## File Structure

- **`LoveWave.hh`** - Header file defining the Love wave class and its properties.
- **`LoveWave.cc`** - Implementation of the Love wave class, including wave propagation and related computations.
- **`utils.hh`** - Header file for utility functions used across the project.
- **`utils.cc`** - Implementation of utility functions.
- **`main.cc`** - Entry point of the simulation, where the Love wave model is instantiated and executed.
- **`CMakeLists.txt`** - CMake build configuration file.

## Getting Started

### Dependencies
- C++17 compiler or newer (GCC, Clang, or equivalent)
- [CMake](https://cmake.org/) 3.10 or newer
- Eigen is vendored in `src/eigen`, so no separate installation is required

### Clone the Repository

```zsh
git clone git@github.com:Gauss963/LoveWave-Solver.git
cd LoveWave-Solver
```

If you use HTTPS instead of SSH:

```zsh
git clone https://github.com/Gauss963/LoveWave-Solver.git
cd LoveWave-Solver
```

### Build the Project

```zsh
cmake -S . -B build
cmake --build build -j4
```

### Run

```zsh
./build/main
```

The program writes the dispersion output to `data/data.bin`.

### Rebuild from Scratch

If you moved the project directory or an old CMake cache points to a previous path, remove the build directory and configure again:

```zsh
rm -rf build
cmake -S . -B build
cmake --build build -j4
```

### HPC Notes

- If the repository was cloned before the Eigen header fix, update the repository and rebuild:

```zsh
git pull
rm -rf build
cmake -S . -B build
cmake --build build -j4
```

- The previous HPC error
  `fatal error: Core: No such file or directory`
  was caused by missing vendored Eigen files in the Git repository, not by CMake itself.

### Plot

If you want to plot $c(\omega)$ or $U(\omega)$, use `src/plot_from_cc.ipynb`.


## Features
- Love wave propagation modeling
- Numerical computations for wave behavior
- Utility functions for mathematical operations

## License

This project is licensed under the MIT License. See the LICENSE file for details.

Author

Gauss Chang
