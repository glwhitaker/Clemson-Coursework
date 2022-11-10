// This file contains method implementation for lowEmission class

#include <iostream>
#include <string>
#include "lowEmission.h"

// default constructor to set default values if needed
lowEmission::lowEmission(){
    make = "N/A";
    model = "N/A";
    year = 2000;
    electricVehicle = false;
    milesPerCharge = 0;
    milesPerGallon = 0;
}
// constructor using values from input if needed
lowEmission::lowEmission(std::string m, std::string md, int y, bool ev, double mpc, double mpg){
    make = m;
    model = md;
    year = y;
    electricVehicle = ev;
    milesPerCharge = mpc;
    milesPerGallon = mpg;
}
// return lowEmission make
std::string lowEmission::getMake(){
    return make;
}
// return lowEmission model
std::string lowEmission::getModel(){
    return model;
}
// return lowEmission year
int lowEmission::getYear(){
    return year;
}
// return lowEmission elecricVehicle (true/false)
std::string lowEmission::getElectricVehicle(){
    if(electricVehicle == true) return "yes";
    else return "no";
}
// return lowEmission mpc
double lowEmission::getMilesPerCharge(){
    return milesPerCharge;
}
// return lowEmission mpg
double lowEmission::getMilesPerGallon(){
    return milesPerGallon;
}
// if string m is not empty, assign m to make
bool lowEmission::setMake(std::string m){
    if(m != ""){
        make = m;
        return true;
    }
    else return false;
}
// if string m is not empty, assign md to model
bool lowEmission::setModel(std::string md){
    if(md != ""){
        model = md;
        return true;
    }
    else return false;
}
// if int y is greater than 1900, assign y to year
bool lowEmission::setYear(int y){
    if(y > 1900){
        year = y;
        return true;
    }
    else return false;
}
// assign to ev to electricVehicle
bool lowEmission::setElectricVehicle(bool ev){
    if(ev == true){
        electricVehicle = ev;
        return true;
    }
    else if(ev == false){
        electricVehicle = ev;
        return true;
    }
    else return false;
}
// if double mpc is greater than 0, assign mpc to milesPerCharge
bool lowEmission::setMilesPerCharge(double mpc){
    if(mpc > 0){
        milesPerCharge = mpc;
        return true;
    }
    else return false;
}
// if double mpg is greater than 0, assign mpc to milesPerGallon
bool lowEmission::setMilesPerGallon(double mpg){
    if(mpg > 0){
        milesPerGallon = mpg;
        return true;
    }
    else return false;
}