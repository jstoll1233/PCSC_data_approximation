//
// Created by kshevche@INTRANET.EPFL.CH on 01.12.20.
//

#ifndef PCSC_EXERCISES_BARYCENTRIC_H
#define PCSC_EXERCISES_BARYCENTRIC_H

#include "Interpolation.h"

/**
 * Class Barycentric for calculating Barycentric interpolation
 */
class Barycentric: public Interpolation {
public:
    /**
     * Constructor for class Barycentric. Directly calls constructor of class Interpolation
     * @param handler object of type DataHandler. Allows to handle the data of the interpolation.
     */
    Barycentric(const DataHandler& handler): Interpolation(handler){};

    /**
     * Overridden method from class Interpolation.
     * @param point of type double. The point in which we want to evaluate the polynomial.
     * @return The polynomial evaluated in point if it is contained in the range of the interpolation data. Nan otherwise
     */
    double Calculate_value_of_interpolant(const double point) override;
};


#endif //PCSC_EXERCISES_BARYCENTRIC_H
