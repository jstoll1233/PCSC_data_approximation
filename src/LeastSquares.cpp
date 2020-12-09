//
// Created by kshevche@INTRANET.EPFL.CH on 26.11.20.
//

#include "LeastSquares.h"
#include <math.h>

LeastSquares::LeastSquares(const DataHandler &data_, const int degree) {
    deg = degree;
    int num_dp = data_.get_number_data_points();
    Eigen::MatrixXf x(num_dp, degree + 1);
    for (int i = 0; i < num_dp; i++) {
        for (int j = 0; j <= degree; j++) {
            x(i, j) = pow(data_.get_data()[i][0], j);
        }
    }
    //std::cout << "Matrix x = " << x << std::endl;

    //creating a vector of the right side of a system of linear equations from last column of data
    Eigen::VectorXf y(num_dp);
    for (int i = 0; i < num_dp; i++) {
        y(i) = data_.get_data()[i][1];
    }
    //std::cout << "Vector y = " << y << std::endl;

    //solution of the system by QR factorization
    coefs = x.householderQr().solve(y);
}

double LeastSquares::Calculate_value_at_point(const double point) {
    double evaluation = 0.0;
    for (int i = 0; i < deg+1; ++i){
        evaluation += coefs(i)*pow(point,i);
    }
    return evaluation;
}
