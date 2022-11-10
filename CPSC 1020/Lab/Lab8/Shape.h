// Grayson Whitaker
// CPSC 1021
// 11/18/2022
// This file contains the Shape class declaration.

#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>
#include <iostream>

class Shape
{
private:
    std::string name;
public:
    Shape() = default;
    Shape(std::string name) : name(name) {};
    // final printName() method to return the name of the shape
    virtual std::string printName() final { return name; }
    // abstract getArea() method
    virtual double getArea() = 0;
};

#endif
