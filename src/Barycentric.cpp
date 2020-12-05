//
// Created by kshevche@INTRANET.EPFL.CH on 01.12.20.
//

#include "Barycentric.h"

double Barycentric::Calculate_value_of_interpolant(const DataHandler& data_, double point) {
    //get the number of data points and data matrix
    int num_dp = data_.get_number_data_points();
    double **x = data_.get_data();

    double value_num = 0;
    double value_den = 0;
    for (int k = 0; k < num_dp; k++) {
        double w = 1.0 / Denominator(data_, k);
        double xdiff = (point - x[k][0]);
        //in case the "point" is a node of x
        if (xdiff == 0) {
            //the value of the interpolating function at this point is the given value
            value_num = x[k][1];
            value_den = 1;
            //to terminate the loop
            k = num_dp;
        } else {
            value_num += w * x[k][1] / xdiff;
            value_den += w / xdiff;
        }
    }
    return value_num / value_den;
}