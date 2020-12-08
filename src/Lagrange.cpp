//
// Created by kshevche@INTRANET.EPFL.CH on 01.12.20.
//

#include "Lagrange.h"

double Lagrange::Numerator(const DataHandler& data_, int k, double point) {
    //get the number of data points and data matrix
    int num_dp = data_.get_number_data_points();
    double **x = data_.get_data();

    //calculate the product of the differences between point and x_j for j != k
    double xdiff = 1;
    for (int j = 0; j < k; j++) {
        xdiff *= (point - x[j][0]);
    }
    for (int j = k + 1; j < num_dp; j++) {
        xdiff *= (point - x[j][0]);
    }
    return xdiff;
}

double Lagrange::Calculate_value_of_interpolant(const DataHandler& data_, double point) {
    int num_dp = data_.get_number_data_points();
    if ((point < data_.get_data()[0][0]) || (point > data_.get_data()[num_dp - 1][0])) {
        throw std::range_error("The point does not belong to the interval");

    }
    double value = 0;
    for (int k = 0; k < num_dp; k++) {
        value += data_.get_data()[k][1] * Numerator(data_, k, point) / Denominator(data_, k);
    }
    return value;
}