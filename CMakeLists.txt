cmake_minimum_required (VERSION 3.0)
project (PCSC_data_approximation)

set(CMAKE_CXX_STANDARD 14)

include_directories("libraries/eigen")

#add_library(pcsc src/pcsc.cc)

#add_executable(data_approximation src/main.cpp src/DataHandler.cpp)

#target_link_libraries()
add_executable(data_approximation src/main.cpp src/DataHandler.cpp src/LeastSquares.cpp src/Interpolation.cpp src/Lagrange.cpp
        src/Barycentric.cpp)


add_subdirectory(googletest)

add_executable(test_pcsc test/test.cpp src/DataHandler.cpp src/LeastSquares.cpp src/Interpolation.cpp src/Lagrange.cpp
        src/Barycentric.cpp)
target_link_libraries(test_pcsc gtest_main gtest pthread)

add_custom_target(test_ ./test_pcsc DEPENDS test_pcsc)