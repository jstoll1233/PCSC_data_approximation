//
// Created by jstoll@INTRANET.EPFL.CH on 27.11.20.
//
//#include "DataHandler.h"
#include <iostream>
#include <fstream>
#include "DataHandler.h"

int main(int argc, char ** argv){
    std::string file_name;
    std::string path;
    path = "../data/";
    std::cout << "Please enter the file name containing the data: " << std::endl;
    std::cin >> file_name;
    path.append(file_name);

    try {
        DataHandler handler(path);
        int dimension = handler.get_dimension();
        int num_data_points = handler.get_number_data_points();
        std::cout << "The problem has a dimension of " << dimension <<
                    " and contains " << num_data_points << " data points." << std::endl;

        int method=0;
        std::cout << "Which method among the following should be used ? " << std::endl;
        std::cout << "1. Least squares " << std::endl;
        std::cout << "2. Lagrange interpolation " << std::endl;
        std::cout << "3. Barycentric interpolation " << std::endl;
        while ((method != 1) and (method != 2) and (method != 3)) {
            std::cout << "Please enter a number from 1 to 3: ";
            std::cin >> method;
        }


    }

    catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }


    return 0;
}