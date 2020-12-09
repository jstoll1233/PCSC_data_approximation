//
// Created by kshevche@INTRANET.EPFL.CH on 01.12.20.
//

#ifndef PCSC_EXERCISES_LAGRANGE_H
#define PCSC_EXERCISES_LAGRANGE_H

#include "Interpolation.h"

/**
 * Class Lagrange for calculating Lagrange interpolating polynomial
 */
class Lagrange: public Interpolation {
private:
    double Numerator(int k, double point);
public:
    Lagrange(const DataHandler& handler): Interpolation(handler){};
    double Calculate_value_of_interpolant(const double point) override;
};


#endif //PCSC_EXERCISES_LAGRANGE_H
