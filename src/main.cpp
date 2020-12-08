//
// Created by jstoll@INTRANET.EPFL.CH on 27.11.20.
//
//#include "DataHandler.h"
#include <iostream>
#include <fstream>
#include "DataHandler.h"
#include "LeastSquares.h"

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
        std::cin >> method;
        int degree = num_data_points - 1;

        switch (method) {
            case 1: {
                std::cout << "For method of least squares, what degree of polynomial should be used ? " <<
                          "knowing that you are working with " << num_data_points << " data points" << std::endl;
                std::cin >> degree;
                if (degree > num_data_points - 1) {
                    std::cout
                            << "You chose a degree higher than (number of data points - 1). Therefore the polynomial is not unique. "
                            << std::endl;
                }
                Eigen::VectorXf coef_poly = LeastSquares(handler, degree);
                break;
            }
            case 2:{
                std::cout << "Method of Lagrange interpolation will generate a polynomial of degree : "
                          << num_data_points-1 << std::endl;

                break;

            }
            case 3:{
                std::cout << "Method of barycentric interpolation will generate a polynomial of degree : "
                          << num_data_points-1 << std::endl;

                break;
            }
            default:{
                std::cout << "you entered an invalid identifier, by default Lagrange is applied." << std::endl;
                break;
            }

        }



    }

    catch (std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    catch (std::invalid_argument &e) {
        std::cerr << e.what() << std::endl;
        return 2;
    }
    catch (std::range_error &e) {
        std::cerr << e.what() << std::endl;
        return 3;
    }




    return 0;
}