#include <iostream>

// totalCharges for in-patient
double calcTotalCharges(double numDays, double roomRate, double hospServices, double medCharges){
    return (numDays * roomRate) + hospServices + medCharges;
}
// totalCharges for out-patient
double calcTotalCharges(double hospServices, double medCharges){
    return hospServices + medCharges;
}