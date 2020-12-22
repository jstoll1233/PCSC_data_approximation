//
// Created by kshevche@INTRANET.EPFL.CH on 26.11.20.
//

#include "LeastSquares.h"
#include <math.h>

LeastSquares::LeastSquares(const DataHandler& handler, const int degree) {
    deg = degree;
    num_dp_ = handler.get_number_data_points();
    data_ = handler.get_data();

    range_max = data_[0][0];
    range_min = data_[0][0];
    Eigen::MatrixXf x(num_dp_, degree + 1);
    for (int i = 0; i < num_dp_; i++) {
        range_max = std::max(range_max, data_[i][0]);
        range_min = std::min(range_min, data_[i][0]);
        for (int j = 0; j <= degree; j++) {
            x(i, j) = pow(data_[i][0], j);
        }
    }
    //std::cout << "Matrix x = " << x << std::endl;

    //creating a vector of the right side of a system of linear equations from last column of data
    Eigen::VectorXf y(num_dp_);
    for (int i = 0; i < num_dp_; i++) {
        y(i) = data_[i][1];
    }
    //std::cout << "Vector y = " << y << std::endl;

    //solution of the system by QR factorization
    coefs = x.householderQr().solve(y);
}

double LeastSquares::Calculate_value_at_point(const double point) {
    /*
    if ((point < range_min) || (point > range_max)) {
        return std::numeric_limits<double>::quiet_NaN();

    }
     */
    double evaluation = 0.0;
    for (int i = 0; i < deg+1; ++i){
        evaluation += coefs(i)*pow(point,i);

    }
    return evaluation;
}
