//
// Created by jstoll@INTRANET.EPFL.CH on 27.11.20.
//
//#include "DataHandler.h"
#include <iostream>
#include "DataHandler.h"
#include "LeastSquares.h"
#include "Lagrange.h"
#include "Barycentric.h"

void interpolation_evaluation(const DataHandler& handler_input, const DataHandler& handler_output, Interpolation& interpolation);
void approximation_evaluation(const DataHandler& handler_input, const DataHandler& handler_output, LeastSquares& approximation);

int main(int argc, char ** argv){
    std::string file_name;
    std::string path;
    path = "../data/";
    std::cout << "Please enter the file name containing the data: " << std::endl;
    std::cin >> file_name;
    path.append(file_name);

    try {
        DataHandler handler_input(path);
        int dimension = handler_input.get_dimension();
        int num_interpolation_points = handler_input.get_number_data_points();
        std::cout << "The problem has a dimension of " << dimension <<
                    " and contains " << num_interpolation_points << " data points." << std::endl;

        std::string file_name_;
        path = "../data/";
        std::cout << "Enter the file name containing the data to evaluate the polynomial on: ";
        std::cin >> file_name_;
        path.append(file_name_);
        DataHandler handler_output(path);

        int method=0;
        std::cout << "Which method among the following should be used ? " << std::endl;
        std::cout << "1. Least squares " << std::endl;
        std::cout << "2. Lagrange interpolation " << std::endl;
        std::cout << "3. Barycentric interpolation " << std::endl;
        std::cin >> method;
        int degree = num_interpolation_points - 1;

        switch (method) {
            case 1:{
                std::cout << "For method of least squares, what degree of polynomial should be used ? " <<
                          "knowing that you are working with " << num_interpolation_points << " data points" << std::endl;
                std::cin >> degree;
                if (degree > num_interpolation_points - 1) {
                    std::cout
                            << "You chose a degree higher than (number of data points - 1). Therefore the polynomial is not unique. "
                            << std::endl;
                }
                LeastSquares approximation(handler_input, degree);

                approximation_evaluation(handler_input, handler_output, approximation);
                break;

            }
            case 2:{
                std::cout << "Method of Lagrange interpolation will generate a polynomial of degree : " << std::endl;
                Lagrange interpolation(handler_input);
                interpolation_evaluation(handler_input, handler_output, interpolation);
                break;

            }
            case 3:{
                std::cout << "Method of barycentric interpolation will generate a polynomial of degree : " <<  std::endl;
                Barycentric interpolation(handler_input);
                interpolation_evaluation(handler_input, handler_output, interpolation);
                break;

            }
            default:{
                std::cout << "you entered an invalid identifier, by default Lagrange is applied." << std::endl;
                Lagrange interpolation(handler_input);
                interpolation_evaluation(handler_input, handler_output, interpolation);
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

void interpolation_evaluation(const DataHandler& handler_input, const DataHandler& handler_output, Interpolation& interpolation) {

    double **data_out = handler_output.get_data();
    int num_dp = handler_output.get_number_data_points();

    std::cout << "Result of evaluation of the data" << std::endl;
    std::cout << "x , poly(x)" << std::endl;
    for (int i = 0; i < num_dp; ++i) {
        double val = data_out[i][0];
        double pred = interpolation.Calculate_value_of_interpolant(val);
        std::cout << val << " , " << pred << std::endl;
    }
}

void approximation_evaluation(const DataHandler& handler_input, const DataHandler& handler_output, LeastSquares& approximation){
    double **data_out = handler_output.get_data();
    int num_dp = handler_output.get_number_data_points();

    std::cout << "Result of evaluation of the data" << std::endl;
    std::cout << "x , poly(x)" << std::endl;
    for (int i = 0; i < num_dp; ++i) {
        double val = data_out[i][0];
        double pred = approximation.Calculate_value_at_point(val);
        std::cout << val << " , " << pred << std::endl;
    }
}