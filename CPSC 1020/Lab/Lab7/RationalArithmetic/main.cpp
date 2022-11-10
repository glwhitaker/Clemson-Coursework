// Grayson Whitaker
// CPSC 1021
// 11/9/2022
// This file includes main function to prompt user to enter two integers
// then print the reduced form of the rational number

#include <iostream>
#include "Rational.h"

using namespace std;

int main(){
    // initialize integer variables
    int val1, val2;

    // prompt user to enter two integers and store as val1, val2
    cout << "Enter the numerator and denominator separated by a space: ";
    cin >> val1 >> val2;

    // instantiate Rational object using val1 and val2 and reduce
    Rational myRational(val1, val2);
    myRational.reduce();

    // output reduced form using overloaded insertion (<<) operator
    cout << "Reduced form: " << myRational << endl;

    return 0;
}