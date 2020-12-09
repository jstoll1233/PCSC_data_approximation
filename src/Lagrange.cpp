//
// Created by kshevche@INTRANET.EPFL.CH on 01.12.20.
//

#include "Lagrange.h"

double Lagrange::Numerator(int k, double point) {
    //get the number of data points and data matrix
    //int num_dp = data_.get_number_data_points();
    //double **x = data_.get_data();

    //calculate the product of the differences between point and x_j for j != k
    double xdiff = 1;
    for (int j = 0; j < k; j++) {
        xdiff *= (point - data_[j][0]);
    }
    for (int j = k + 1; j < num_dp_; j++) {
        xdiff *= (point - data_[j][0]);
    }
    return xdiff;
}

double Lagrange::Calculate_value_of_interpolant(const DataHandler& da, double point) {
    //int num_dp = data_.get_number_data_points();
    if ((point < range_min) || (point > range_max)) {
        throw std::range_error("The point does not belong to the interval");

    }
    double value = 0;
    for (int k = 0; k < num_dp_; k++) {
        value += data_[k][1] * Numerator(k, point) / Denominator(k);
    }
    return value;
}