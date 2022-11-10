// Grayson Whitaker
// CPSC 1021
// 11/9/2022
// This file includes implementation for reduce function (Rational class)
// and overloaded instertion (<<) operator

#include <iostream>
#include <algorithm>
#include "Rational.h"

void Rational::reduce(){
    // initialize integer for denominator
    int denominator;

    // utilized __gcd() found in <algorithm> library to find GCD of two values
    denominator = std::__gcd(reducedVal1, reducedVal2);

    // divide original values by GCD
    reducedVal1 = reducedVal1 / denominator;
    reducedVal2 = reducedVal2 / denominator;

    // ensure denominator is positive
    if(reducedVal2 < 0){
        reducedVal1 = reducedVal1 * -1;
        reducedVal2 = reducedVal2 * -1;
    }
}

std::ostream& operator<<(std::ostream& os, const Rational& rn){
    os << rn.reducedVal1 << "/" << rn.reducedVal2;
    return os;
}