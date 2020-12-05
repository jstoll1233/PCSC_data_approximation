//
// Created by kshevche@INTRANET.EPFL.CH on 01.12.20.
//

#include "Interpolation.h"

double Interpolation::Denominator(const DataHandler& data_, int k) {
    //get the number of data points and matrix of data
    int num_dp = data_.get_number_data_points();
    double **x = data_.get_data();

    //calculate the product of the differences between x_k and x_j for j != k
    double xdiff = 1;
    for (int j = 0; j < k; j++) {
        xdiff *= (x[k][0] - x[j][0]);
    }
    for (int j = k + 1; j < num_dp; j++) {
        xdiff *= (x[k][0] - x[j][0]);
    }
    return xdiff;
}