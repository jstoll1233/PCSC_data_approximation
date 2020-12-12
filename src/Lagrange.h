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
    /**
     * Method that computes one term of the numerator of the lagrange polynomial definition.
     * Note that the numerator can be divided in one term per interpolation data point (corresponding to one value of k)
     * Note also that the denominator, being equal between Lagrange and Barycentric, is defined in
     * the class Interpolation.
     * @param k an index allowing to iterate over all data points.
     * @param point the point in which we want to evaluate the polynomial.
     * @return One term of the numerator of the lagrange expression.
     */
    double Numerator(int k, double point);
public:
    /**
     * Constructor for class Lagrange. Directly calls constructor of class Interpolation
     * @param handler object of type DataHandler. Allows to handle the data of the interpolation.
     */
    Lagrange(const DataHandler& handler): Interpolation(handler){};

    /**
     * Overridden method from class Interpolation.
     * @param point of type double. The point in which we want to evaluate the polynomial.
     * @return The polynomial evaluated in point if it is contained in the range of the interpolation data. Nan otherwise
     */
    double Calculate_value_of_interpolant(const double point) override;
};


#endif //PCSC_EXERCISES_LAGRANGE_H
