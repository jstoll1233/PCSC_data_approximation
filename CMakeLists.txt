cmake_minimum_required(VERSION 3.17)
project(PCSC_data_approximation)

set(CMAKE_CXX_STANDARD 14)

add_executable(PCSC_data_approximation src/main.cpp src/DataHandler.cpp src/LeastSquares.cpp src/Interpolation.cpp
        src/Lagrange.cpp src/Barycentric.cpp)
include_directories("libraries/eigen/eigen")
