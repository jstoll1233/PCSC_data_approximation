//
// Created by kshevche@INTRANET.EPFL.CH on 30.11.20.
//

#include <iostream>
#include <Eigen/QR>

#include "DataHandler.h"

#ifndef PCSC_EXERCISES_LEASTSQUARES_H
#define PCSC_EXERCISES_LEASTSQUARES_H

/**
     * Function for least squares aprroximation
     * @param data_ containing the data
     * @param degree - degree of approximating polynomial
     * @return vector of polynomial coefficients
     **/
Eigen::VectorXf LeastSquares(const DataHandler& data_, const int degree);


#endif //PCSC_EXERCISES_LEASTSQUARES_H
