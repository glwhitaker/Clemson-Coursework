// Grayson Whitaker
// CPSC 1021
// 9/26/2022
// This file contains implementation of methods for Patient class

#include <iostream>
#include "Patient.h"

// default constructor to set all members to default values
Patient::Patient(){
    patientType = 'I';
    days = 0;
    rate = 0.0;
    services = 0.0;
    medication = 0.0;
}
Patient::Patient(char p, double s, double m){
    patientType = p;
    services = s;
    medication = m;
}
// constructor to be used with user input
Patient::Patient(char p, int d, double r, double s, double m){
    patientType = p;
    days = d;
    rate = r;
    services = s;
    medication = m;
}
// validate integer input is greater than/equal to 0
bool Patient::validateInput(int input){
    if(input < 0) return false;
    else return true;
}
// validate double input is greater than/equal to 0
bool Patient::validateInput(double input){
    if(input < 0) return false;
    else return true;
}
// return member days
int Patient::getDays(){
    return days;
}
// set member days if validateInput returns true
bool Patient::setDays(int d){
    if(validateInput(d)){
        days = d;
        return true;
    }
    else return false;
}
// return member rate
double Patient::getRate(){
    return rate;
}
// set member rate if validateInput returns true
bool Patient::setRate(double r){
    if(validateInput(r)){
        rate = r;
        return true;
    }
    else return false;
}
// return member services
double Patient::getServices(){
    return services;
}
// set member services if validateInput returns true
bool Patient::setServices(double s){
    if(validateInput(s)){
        services = s;
        return true;
    }
    else return false;
}
// return member medication
double Patient::getMedication(){
    return medication;
}
// set member medicaiton if validateInput returns true;
bool Patient::setMedication(double m){
    if(validateInput(m)){
        medication = m;
        return true;
    }
    else return false;
}
// return member patientType
char Patient::getPatientType(){
    return patientType;
}
// set member patientType if validateInput returns true;
bool Patient::setPatientType(char p){
    if(validateInput(p)){
        patientType = p;
        return true;
    }
    else return false;
}
// calculate patient's total charges for hospital visit
double Patient::calcTotalCharges(){
    return (getDays() * getRate()) + getServices() + getMedication();
}