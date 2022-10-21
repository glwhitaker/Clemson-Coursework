#include <iostream>
#include <string>
#include "car.h"

Car::Car() {
  make = "Company";
  model = "CarName";
  year = 0;
  licensePlate = "123ABC";
  numDoors = 2;
}
Car::Car(std::string ma, std::string mo, std::string l, int y, int n) {
  setMake(ma);
  setModel(mo);
  setLicensePlate(l);
  setYear(y);
  setNumDoors(n);
}

bool Car::setMake(std::string m) {
  if(m != ""){
    make = m;
    return true;
  }
  else return false;
}
bool Car::setModel(std::string md) {
  if(md != ""){
    model = md;
    return true;
  }
  else return false;
}
bool Car::setLicensePlate(std::string l) {
  if(l != ""){
    licensePlate = l;
    return true;
  }
  else return false;
}
bool Car::setYear(int y) {
  if (y < 1850) {
    return false;
  }
  else {
    year = y;
    return true;
  }
}
bool Car::setNumDoors(int n) {
  if (!(numDoors == 2 || numDoors == 3 || numDoors == 4)) {
    return false;
  }
  else {
    numDoors = n;
    return true;
  }
}
std::string Car::getMake() {
  return make;
}
std::string Car::getModel() {
  return model;
}
std::string Car::getLicensePlate() {
  return licensePlate;
}
int Car::getYear() {
  return year;
}
int Car::getNumDoors() {
  return numDoors;
}
