// Grayson Whitaker
// CPSC 1021
// 11/18/2022
// This file contains the Square class declaration.

#ifndef SQUARE_H_
#define SQUARE_H_

#include "Shape.h"

class Square: public Shape {
    private:
        double side;
    public:
        Square() = default;
        // constructor calls base class constructor and sets name to "Square"
        Square(double side) : Shape("Square"), side(side) {};
        double getArea();
};

#endif
