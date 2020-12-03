//
// Created by kshevche@INTRANET.EPFL.CH on 26.11.20.
//

#include "LeastSquares.h"

Eigen::VectorXf LeastSquares(const DataHandler& data_, const int degree) {
    //get the number of data points
    int num_dp = data_.get_number_data_points();

    //creating a matrix of the left side of a system of linear equations
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
    Eigen::VectorXf w = x.householderQr().solve(y);
    //std::cout << "Vector w = " << w << std::endl;
    //std::cout << "x * w = " << x * w << std::endl;
    return w;
}
