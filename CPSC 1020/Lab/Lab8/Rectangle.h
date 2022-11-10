// Grayson Whitaker
// CPSC 1021
// 11/18/2022
// This file contains the Rectangle class declaration.

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Shape.h"

class Rectangle: public Shape {
    private:
        double length;
        double width;
    public:
        Rectangle() = default;
        // constructor calls base class constructor and sets name to "Rectangle"
        Rectangle(double length, double width) : Shape("Rectangle"), length(length), width(width) {};
        double getArea();
};

#endif
