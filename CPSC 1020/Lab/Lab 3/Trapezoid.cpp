#include <iostream>
#include "Trapezoid.h"

double Trapezoid::getBase1(){
    return base1;
}

bool Trapezoid::setBase1(double b){
    if(b > 0){
        base1 = b;
        return true;
    }
    else{
        return false;
    }
}

double Trapezoid::getBase2(){
    return base2;
}

bool Trapezoid::setBase2(double b){
    if(b > 0){
        base2 = b;
        return true;
    }
    else{
        return false;
    }
}

double Trapezoid::getHeight(){
    return height;
}

bool Trapezoid::setHeight(double h){
    if(h > 0){
        height = h;
        return true;
    }
    else{
        return false;
    }
}

double Trapezoid::calcArea(){
    return ((getBase1() + getBase2()) / 2) * getHeight();
}