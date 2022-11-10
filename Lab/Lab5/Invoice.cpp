#include <iostream>
#include <string>
#include "Invoice.h"

Invoice::Invoice(){
    permitPrice = 0;
    discount = 0;
    serviceCharge = 0;
    permitType = "N/A";
}

Invoice::Invoice(double pp, double d, double sc){
    permitPrice = pp;
    discount = d;
    serviceCharge = sc;
}

double Invoice::getPermitPrice(){
    return permitPrice;
}

double Invoice::getDiscount(){
    return discount;
}

double Invoice::getServiceCharge(){
    return serviceCharge;
}

std::string Invoice::getPermitType(){
    return permitType;
}

bool Invoice::setPermitPrice(double pp){
    if(pp > 0){
        permitPrice = pp;
        return true;
    }
    else return false;
}

bool Invoice::setDiscount(double d){
    if(d >= 0){
        discount = d;
        return true;
    }
    else return false;
}

bool Invoice::setServiceCharge(double sc){
    if(sc >= 0){
        serviceCharge = sc;
        return true;
    }
    else return false;
}

bool Invoice::setPermitType(std::string pt){
    if(pt != ""){
        permitType = pt;
        return true;
    }
    else return false;
}

double Invoice::calcTotalPrice(){
    return getPermitPrice() * (1 - getDiscount()) + getServiceCharge();
}

std::string Invoice::invoicePrintOut(Employee& myPerson){
    std::string invoiceString = "";
    invoiceString += "Name: " + myPerson.getName() + "\n";
    invoiceString += "Address: " + myPerson.getAddress() + "\n";
    invoiceString += "Email: " + myPerson.getEmail() + "\n";
    invoiceString += "Employee number: " + std::to_string(myPerson.getEmployeeNumber()) + "\n";
    invoiceString += "Year hired: " + std::to_string(myPerson.getHireYear()) + "\n";
    return invoiceString;
}

std::string Invoice::invoicePrintOut(Student& myPerson){
    std::string invoiceString = "";
    invoiceString += "Name: " + myPerson.getName() + "\n";
    invoiceString += "Address: " + myPerson.getAddress() + "\n";
    invoiceString += "Email: " + myPerson.getEmail() + "\n";
    invoiceString += "Student number: " + std::to_string(myPerson.getStudentIDNum()) + "\n";
    invoiceString += "Age: " + std::to_string(myPerson.getAge()) + "\n";
    return invoiceString;
}

std::string Invoice::invoicePrintOut(Visitor& myPerson){
    std::string invoiceString = "";
    invoiceString += "Name: " + myPerson.getName() + "\n";
    invoiceString += "Address: " + myPerson.getAddress() + "\n";
    invoiceString += "Email: " + myPerson.getEmail() + "\n";
    invoiceString += "Reason for visit: " + myPerson.getReason() + "\n";
    invoiceString += "Alumni: " + myPerson.getIsAlumni() + "\n";
    return invoiceString;
}

std::string Invoice::invoicePrintOut(Vendor& myPerson){
    std::string invoiceString = "";
    invoiceString += "Name: " + myPerson.getName() + "\n";
    invoiceString += "Address: " + myPerson.getAddress() + "\n";
    invoiceString += "Email: " + myPerson.getEmail() + "\n";
    invoiceString += "Merchandise: " + myPerson.getSellObject() + "\n";
    invoiceString += "Employee count: " + to_string(myPerson.getEmployeeCount()) + "\n";
    return invoiceString;
}

std::string Invoice::invoicePrintOut(Car& myVehicle){
    std::string invoiceString = "";
    invoiceString += "Make: " + myVehicle.getMake() + "\n";
    invoiceString += "Model: " + myVehicle.getModel() + "\n";
    invoiceString += "Year: " + std::to_string(myVehicle.getYear()) + "\n";
    invoiceString += "License plate: " + myVehicle.getLicensePlate() + "\n";
    invoiceString += "Number of doors: " + std::to_string(myVehicle.getNumDoors()) + "\n";
    return invoiceString;
}

std::string Invoice::invoicePrintOut(lowEmission& myVehicle){
    std::string invoiceString = "";
    invoiceString += "Make: " + myVehicle.getMake() + "\n";
    invoiceString += "Model: " + myVehicle.getModel() + "\n";
    invoiceString += "Year: " + std::to_string(myVehicle.getYear()) + "\n";
    invoiceString += "Electric Vehicle: " + myVehicle.getElectricVehicle() + "\n";
    if(myVehicle.getElectricVehicle() == "yes") {
        invoiceString += "Miles per charge: " + to_string(myVehicle.getMilesPerCharge()) + "\n";
    }
    else{
        invoiceString += "Miles per gallon: " + to_string(myVehicle.getMilesPerGallon()) + "\n";
    }
    return invoiceString;
}

std::string Invoice::invoicePrintOut(Motorcycle& myVehicle){
    std::string invoiceString = "";
    invoiceString += "Make: " + myVehicle.getMake() + "\n";
    invoiceString += "Model: " + myVehicle.getModel() + "\n";
    invoiceString += "Year: " + std::to_string(myVehicle.getYear()) + "\n";
    invoiceString += "Color: " + myVehicle.getColor() + "\n";
    invoiceString += "Radio: " + myVehicle.getHasRadio() + "\n";
    return invoiceString;
}

std::string Invoice::invoicePrintOut(Moped& myVehicle){
    std::string invoiceString = "";
    invoiceString += "Make: " + myVehicle.getMake() + "\n";
    invoiceString += "Model: " + myVehicle.getModel() + "\n";
    invoiceString += "Year: " + std::to_string(myVehicle.getYear()) + "\n";
    invoiceString += "Two-seater: " + myVehicle.getTwoSeater() + "\n";
    invoiceString += "Basket: " + myVehicle.getBasket() + "\n";
    return invoiceString;
}

std::string Invoice::invoicePrintOut(){
    std::string invoiceString = "";
    invoiceString += "Permit Type: " + permitType + "\n";
    invoiceString += "Permit Price: $" + std::to_string(permitPrice) + "\n";
    return invoiceString;
}

