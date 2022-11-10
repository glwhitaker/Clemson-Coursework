// Grayson Whitaker
// CPSC 1021
// 11/18/2022
// This file contains the Trapezoid class declaration.

#ifndef TRAPEZOID_H_
#define TRAPEZOID_H_

#include "Shape.h"

class Trapezoid: public Shape {
    private:
        double base1;
        double base2;
        double height;
    public:
        Trapezoid() = default;
        // constructor calls base class constructor and sets name to "Trapezoid"
        Trapezoid(double base1, double base2, double height) : Shape("Trapezoid"), base1(base1), base2(base2), height(height) {};
        double getArea();
};

#endif
