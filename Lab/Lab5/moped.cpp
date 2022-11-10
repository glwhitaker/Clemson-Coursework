//Sam Ogle
//CPSC 1021
//10/10/22
//Description: Vehicle Class Definitions

#include <iostream>
#include <string>
#include "moped.h"

Moped::Moped(){
    make = "N/A";
    model = "N/A";
    year = 2000;
    twoSeater = false;
    basket = false;
}

bool Moped::setMake(std::string m) {
    if (m != "") {
        make = m;
        return true;
    }
    else {
        return false;
    }
}

bool Moped::setModel(std::string md) {
    if (md != "") {
        model = md;
        return true;
    }
    else {
        return false;
    }
}

bool Moped::setYear(int y) {
    if (y > 0) {
        year = y;
        return true;
    }
    else {
        return false;
    }
}

bool Moped::setTwoSeater(bool mopedSeats) {
    if (mopedSeats == true) {
        twoSeater = mopedSeats;
        return true;
    }
    else if(mopedSeats == false) {
        twoSeater = mopedSeats;
        return true;
    }
    else {
        return false;
    }
}

bool Moped::setBasket(bool baskets) {
    if (baskets == true) {
        basket = baskets;
        return true;
    }
    else if (baskets == false) {
        basket = baskets;
        return true;
    }
    else {
        return false;
    }
}

std::string Moped::getMake() {
    return make;
}

std::string Moped::getModel() {
    return model;
}

int Moped::getYear() {
    return year;
}

std::string Moped::getTwoSeater() {
    if(twoSeater == true) return "yes";
    else return "no";
}

std::string Moped::getBasket() {
    if(basket == true) return "yes";
    else return "no";
}

