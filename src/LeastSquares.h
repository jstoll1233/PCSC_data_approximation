//
// Created by kshevche@INTRANET.EPFL.CH on 30.11.20.
//
#ifndef PCSC_EXERCISES_LEASTSQUARES_H
#define PCSC_EXERCISES_LEASTSQUARES_H

#include <iostream>
#include <Eigen/QR>

#include "DataHandler.h"

class LeastSquares{

    public:
    LeastSquares(const DataHandler& data_, const int degree);
    double Calculate_value_at_point(const double point);

    private:
    Eigen::VectorXf coefs;
    int deg;
};
    /**
     * Function for least squares aprroximation
     * @param data_ containing the data
     * @param degree - degree of approximating polynomial
     * @return vector of polynomial coefficients
     **/


#endif //PCSC_EXERCISES_LEASTSQUARES_H
