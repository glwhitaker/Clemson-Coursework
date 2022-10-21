#include <iostream>
#include <string>
#include "motorcycle.h"

using namespace std;

Motorcycle :: Motorcycle() {
    make = "x";
    model = "x";
    year = 0;
    hasRadio = true;
    color = "x";
}
Motorcycle :: Motorcycle(string m, string md, int y, bool hasR, string c) {
    make = m;
    model = md;
    year = y;
    hasRadio = hasR;
    color = c;
}

void Motorcycle :: setMake(string m) {
    make = m;
}
string Motorcycle :: getMake() {
    return make;
}

void Motorcycle :: setModel(string md) {
    model = md;
}
string Motorcycle :: getModel() {
    return model;
}

void Motorcycle :: setYear(int y) {
    year = y;
}
int Motorcycle :: getYear() {
    return year;
}

void Motorcycle :: setHasRadio(bool hasR) {
    hasRadio = hasR;
}
std::string Motorcycle :: getHasRadio() {
    if(hasRadio == true) return "yes";
    else return "no";
}

void Motorcycle :: setColor(string c) {
    color = c;
}
string Motorcycle :: getColor() {
    return color;
}
