// This file contains method implementation for Employee class

#include <iostream>
#include <string>
#include "employee.h"

// default constructor to set default values if needed
Employee::Employee(){
    name = "N/A";
    address = "N/A";
    email = "N/A";
    employeeNumber = 10000000;
    hireYear = 2022;
}
// constructor using values from input if needed
Employee::Employee(std::string n, std::string a, std::string e, int en, int y){
    name = n;
    address = a;
    email = e;
    employeeNumber = en;
    hireYear = y;
}
// return Employee name
std::string Employee::getName(){
    return name;
}
// return Employee address
std::string Employee::getAddress(){
    return address;
}
// return Employee email
std::string Employee::getEmail(){
    return email;
}
// return Employee number
int Employee::getEmployeeNumber(){
    return employeeNumber;
}
// return Employee hireYear
int Employee::getHireYear(){
    return hireYear;
}
// if string n is not empty, assign n to name
bool Employee::setName(std::string n){
    if(n != ""){
        name = n;
        return true;
    }
    else return false;
}
// if string a is not empty, assign a to address
bool Employee::setAddress(std::string a){
    if(a != ""){
        address = a;
        return true;
    }
    else return false;
}
// if string em is not empty, assign em to email
bool Employee::setEmail(std::string e){
    if((e.find('@') != std::string::npos) && (e.find('.') != std::string::npos)){
        email = e;
        return true;
    }
    else return false;
}
// if n is an 8-digit number (valid employee number), assign n to employeeNumber
bool Employee::setEmployeeNumber(int en){
    if(en > 9999999 && en < 100000000){
        employeeNumber = en;
        return true;
    }
    else return false;
}
// if hire year is valid (from founding of Clemson to current year), assign y t o hireYear
bool Employee::setHireYear(int y){
    if(y > 1889 && y < 2023){
        hireYear = y;
        return true;
    }
    else return false;
}