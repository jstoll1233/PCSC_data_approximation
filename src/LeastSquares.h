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
    /**
     * Constructor for class LeastSquares. Determination of the coefficients of the polynomial
     * @param handler object of type DataHandler. Allows to handle the data of the approximation.
     * @param degree the degree of the polynomial that is determined with least squares method.
     */
    LeastSquares(const DataHandler& handler, const int degree);
    /**
     * Method that allows to evaluate the polynomial previously determined with least squares method in a point.
     * @param point the in which we want to evaluate the polynomial.
     * @return the value of the polynomial in the indicated point. If the point is outside of the range determined
     * by the input data, nan value is returned.
     *
     */
    double Calculate_value_at_point(const double point);

    private:
    /**
     * Vector of type Eigen::VectorXf containing the coefficients of the polynomial.
     * Found with least squares.
     */
    Eigen::VectorXf coefs;
    /**
     * Degree of the polynomial that should be generated with least squares.
     */
    int deg;
    /**
     * The data that should be used for the data approximation with least squares.
     */
    double** data_;
    /**
     * Number of data points for the data approximation.
     */
    int num_dp_;
    /**
     * Minimum of the range on which data approximation can be performed. Determined by
     * the input data.
     */
    double range_min;
    /**
     * Maximum of the range on which data approximation can be performed. Determined by
     * the input data.
     */
    double range_max;
};
    
#endif //PCSC_EXERCISES_LEASTSQUARES_H
