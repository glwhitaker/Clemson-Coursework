// Grayson Whitaker
// CPSC 1021
// 11/9/2022
// This file includes class definition for Rational class

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational{
    private:
        int reducedVal1 {1};
        int reducedVal2 {1};
    public:
        Rational() = default;
        Rational(int val1, int val2) : reducedVal1 {val1}, reducedVal2 {val2} {}
        void reduce();
        friend std::ostream& operator<<(std::ostream& os, const Rational& rn);
};

#endif