# Love Wave Simulation

This project implements a Love wave simulation using C++. It consists of multiple source files for wave modeling and utility functions.

## File Structure

- **`LoveWave.hh`** - Header file defining the Love wave class and its properties.
- **`LoveWave.cc`** - Implementation of the Love wave class, including wave propagation and related computations.
- **`utils.hh`** - Header file for utility functions used across the project.
- **`utils.cc`** - Implementation of utility functions.
- **`main.cc`** - Entry point of the simulation, where the Love wave model is instantiated and executed.
- **`CMakeLists.txt`** - CMake build configuration file.

## Compilation and Usage

### Dependencies
- C++ compiler (GCC, Clang, or equivalent)
- [CMake](https://cmake.org/) (for building the project)
- [Eigen](https://eigen.tuxfamily.org) (already included)

### Building the Project

1. Create a build directory:
   ```zsh
   mkdir build && cd build
   ```
2.	Run CMake to configure the project:
	```zsh
	cmake ..
	```
3.	Compile the project:
	```zsh
	make
	```
4.	Execution

After compilation, run the program using:

```zsh
./main
```


### Features
	•	Love wave propagation modeling
	•	Numerical computations for wave behavior
	•	Utility functions for mathematical operations

## License

This project is licensed under the MIT License. See the LICENSE file for details.

Author

Gauss Chang