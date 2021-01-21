# PCSC_data_approximation
This program performs data interpolation by Lagrange and Barycentric interpolation and data approximation by Least-squares method for two-dimensional data.

Structure of this project is following:
- folder "src", which contains files with code of our program - classes DataHandler, Interpolation, Lagrange, Barycentric, LeastSquares and main.cpp file;
- folder "data", which contains examples of 2 data files - "template_file.txt', that includes data on which the interpolation or approximation is performed, and "template_evaluate", that includes data on which the interpolation or approximation is evaluated;
- folder "test", which contains test.cpp file, showing tests for this project, and data files with wrong format;
- folder "doc" with documentation of the project;
- folder "libraries" with "eigen" library;
- folder "googletest".

Before running our program, you should install the following libraries:
- eigen, that you can clone from https://gitlab.com/libeigen/eigen.git into folder "libraries";
- gooogletest, that you can clone from https://github.com/google/googletest.git.

For execution of the program:
- move to folder "PCSC_data_approximation" and use the following commands:
- mkdir build
- cd build
- cmake ..
- make
- ./data_approximation  (or  ./test_pcsc for execution of tests)

For generation of the documentation (with doxygen):
- move to folder "PCSC_data_approximation/doc/html" and use the following commands:
- firefox index.html
