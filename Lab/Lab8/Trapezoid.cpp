// Grayson Whitaker
// CPSC 1021
// 11/18/2022
// This file contains implementation of the Trapezoid class.

#include "Trapezoid.h"

// implement getArea()
double Trapezoid::getArea() {
    return (base1 + base2) * height / 2;
}
