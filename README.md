# PCSC_data_approximation
This program performs data interpolation by Lagrange and Barycentric interpolation and data approximation by least-squares method.

Structure of this project:
- folder "src", which contains files with code of our program - classes DataHandler, Interpolation, Lagrange, Barycentric, LeastSquares and main.cpp file;
- folder "data", which contains examples of 2 data files - "template_file.txt', that includes data on which the interpolation or approximation is performed, and "template_evaluate", that includes data on which the interpolation or approximation is evaluated;
- folder "test", which contains test.cpp file, showing tests for this project, and data files with wrong format;
- folder "doc" with documentation of the project;
- folder "libraries" with eigen library;
- folder "googletest".

To run our prohram, you should install following libraries:
- eigen;
- gooogletest.
