cmake_minimum_required(VERSION 3.10)
project(Seismology)

set(CMAKE_CXX_STANDARD 17)

set(EIGEN3_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/src/eigen")
include_directories(${EIGEN3_INCLUDE_DIR})


add_executable(main src/main.cc src/utils.cc src/LoveWave.cc)
