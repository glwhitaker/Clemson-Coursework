// Grayson Whitaker
// CPSC 1021
// 11/18/2022
// This file includes the main function for Lab 8 which calculates areas for different shapes using inheritance and polymorphism.

#include "Shape.h"
#include "Rectangle.h"
#include "Square.h"
#include "Circle.h"
#include "Trapezoid.h"
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    // instantiate objects for each shape using paramter constructors
    Circle circle(2.0);
    Square square(2.0);
    Rectangle rectangle(2.5, 3.0);
    Trapezoid trapezoid(2.5, 3.5, 4.0);

    // create a vector of Shape pointers containing the addresses of the objects
    vector<Shape*>shapeVect {&circle, &square, &rectangle, &trapezoid};

    // print the name of each shape and its area using a range-based for loop and the printName() and getArea() functions
    for (auto shape : shapeVect) {
        cout << fixed << setprecision(1) << "Area of " << shape->printName() << " is: " << shape->getArea() << endl;
    }

    return 0;
}
