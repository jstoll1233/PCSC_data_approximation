//
// Created by kshevche@INTRANET.EPFL.CH on 01.12.20.
//

#ifndef PCSC_EXERCISES_INTERPOLATION_H
#define PCSC_EXERCISES_INTERPOLATION_H

#include "DataHandler.h"

/**
 * Class Interpolation for calculating interpolating function
 */
class Interpolation {
protected:
    double Denominator(int k);
    double** data_;
    int num_dp_;
    double range_min;
    double range_max;
public:
    Interpolation(const DataHandler& handler);
    int get_range_min() const;
    int get_range_max() const;
    /**
    * Function for calculating the value of the interpolating function
    * @param data_ containing the data
    * @param point - the point where you want to calculate the value of the interpolating function
    * @return value of the interpolating function at point x
    **/
    virtual double Calculate_value_of_interpolant(double point) = 0;
};


#endif //PCSC_EXERCISES_INTERPOLATION_H
