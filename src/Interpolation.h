//
// Created by kshevche@INTRANET.EPFL.CH on 01.12.20.
//

#ifndef PCSC_EXERCISES_INTERPOLATION_H
#define PCSC_EXERCISES_INTERPOLATION_H

#include "DataHandler.h"
#include <limits>

/**
 * Class Interpolation for calculating interpolating function
 */
class Interpolation {
protected:
    /**
     * Method that computes one term of the denominator for both the Barycentric and the lagrange polynomial.
     * Note that the denominator can be divided in one term per interpolation data point (corresponding to one value of k)
     * Note also that the nominator of the polynomial, being different between Lagrange and Barycentric, is defined in
     * the corresponding classes.
     * @param k an index allowing to iterate over all data points.
     * @return One term of the denominator of the lagrange expression.
     */
    double Denominator(int k);
    /**
     * The data that should be used for the data interpolation.
     */
    double** data_;
    /**
     * Number of data points for the data interpolation.
     */
    int num_dp_;
    /**
     * Minimum of the range on which data interpolation (and evaluation) can be performed. Determined by
     * the input data.
     */
    double range_min;
    /**
     * Maximum of the range on which data interpolation (and evaluation) can be performed. Determined by
     * the input data.
     */
    double range_max;
public:
    /**
     * Constructor of the class Interpolation. Inherited and used in both Lagrange and Barycentric.
     * @param handler object of type DataHandler. Allows to handle the data for interpolation.
     */
    Interpolation(const DataHandler& handler);
    //int get_range_min() const;
    //int get_range_max() const;
    /**
    * Function for calculating the value of the interpolating function. Defined in the daughter classes.
    * @param point - the point where you want to calculate the value of the interpolating function
    * @return value of the interpolating function at point x
    **/
    virtual double Calculate_value_of_interpolant(double point) = 0;
};

#endif //PCSC_EXERCISES_INTERPOLATION_H
