//
// Created by kshevche@INTRANET.EPFL.CH on 01.12.20.
//

#include "Interpolation.h"

Interpolation::Interpolation(const DataHandler& handler)
{
    num_dp_ = handler.get_number_data_points();
    data_ = handler.get_data();

    range_max = data_[0][0];
    range_min = data_[0][0];

    for (int i = 0; i< num_dp_; ++i){
        range_max = std::max(range_max, data_[i][0]);
        range_min = std::min(range_min, data_[i][0]);
    }
}
double Interpolation::Denominator(int k) {
    //get the number of data points and matrix of data
    //int num_dp = data_.get_number_data_points();
    //double **x = data_.get_data();

    //calculate the product of the differences between x_k and x_j for j != k
    double xdiff = 1;
    for (int j = 0; j < k; j++) {
        xdiff *= (data_[k][0] - data_[j][0]);
    }
    for (int j = k + 1; j < num_dp_; j++) {
        xdiff *= (data_[k][0] - data_[j][0]);
    }
    return xdiff;
}