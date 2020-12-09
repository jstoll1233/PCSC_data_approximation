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
    Barycentric(const DataHandler& handler): Interpolation(handler){};
    double Calculate_value_of_interpolant(const double point) override;
};


#endif //PCSC_EXERCISES_BARYCENTRIC_H
