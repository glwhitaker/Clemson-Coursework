// Grayson Whitaker
// CPSC 1021
// 11/18/2022
// This file contains the Circle class declaration.

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"

class Circle: public Shape{
    private:
        double radius;
        const double PI = 3.14;
    public:
        Circle() = default;
        // constructor calls base class constructor and sets name to "Circle"
        Circle(double radius) : Shape("Circle"), radius(radius) {};
        double getArea();
};

#endif
