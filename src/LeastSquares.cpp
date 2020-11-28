#include <iostream>
#include <Eigen/QR>

#include "DataHandler.h"


Eigen::VectorXf LeastSquares(const DataHandler& data_, const int degree) {
    //get the number of data points and dimension of data
    int num_dp = data_.get_number_data_points();
    int dim = data_.get_dimension();

    //creating a matrix of the left side of a system of linear equations
    Eigen::MatrixXf x(num_dp, (dim - 1) * degree + 1);
    for (int i = 0; i < num_dp; i++) {
        //adding a feature vector from 1 to account for offset
        x(i, 0) = 1;
        int index = 1;
        for (int k = 1; k <= degree; k++) {
            for (int j = 1; j < dim; j++) {
                x(i, index) = pow(data_.get_data()[i][j - 1], k);
                index++;
            }
        }
    }
    //std::cout << "Matrix x = " << x << std::endl;

    //creating a vector of the right side of a system of linear equations from last column of data
    Eigen::VectorXf y(num_dp);
    for (int i = 0; i < num_dp; i++) {
        y(i) = data_.get_data()[i][dim - 1];
    }
    //std::cout << "Vector y = " << y << std::endl;

    //solution of the system by qr factorization
    Eigen::VectorXf w = x.householderQr().solve(y);
    //std::cout << "Vector w = " << w << std::endl;
    //std::cout << "x * w = " << x * w << std::endl;
    return w;
}
