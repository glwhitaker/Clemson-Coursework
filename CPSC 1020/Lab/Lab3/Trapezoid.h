#ifndef TRAPEZOID_H
#define TRAPEZOID_H

class Trapezoid{
    private:
        double base1;
        double base2;
        double height;
    public:
        double getBase1();
        bool setBase1(double);
        double getBase2();
        bool setBase2(double);
        double getHeight();
        bool setHeight(double);
        double calcArea();
};

#endif