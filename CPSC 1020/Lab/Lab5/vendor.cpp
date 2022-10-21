#include <iostream>
#include <string>
#include "vendor.h"

Vendor::Vendor() {
  name = "User";
  address = "123 streetname, city, state, zipcode";
  email = "user@email.com";
  sellObject = "Food";
  employeeCount = 0;
}
Vendor::Vendor(std::string n, std::string a, std::string e, std::string s, int c) {
  setName(n);
  setAddress(a);
  setEmail(e);
  setSellObject(s);
  setEmployeeCount(c);
}
bool Vendor::setName(std::string n) {
  if(n != ""){
    name = n;
    return true;
  }
  else return false;
}
bool Vendor::setAddress(std::string a) {
  if(a != ""){
    address = a;
    return true;
  }
  else return false;
}
bool Vendor::setEmail(std::string e) {
  if((e.find('@') != std::string::npos) && (e.find('.') != std::string::npos)){
        email = e;
        return true;
    }
    else return false;
}
bool Vendor::setSellObject(std::string s) {
  if(s != ""){
    sellObject = s;
    return true;
  }
  else return false;
}
bool Vendor::setEmployeeCount(int c) {
  if (c < 0) {
    return false;
  }
  else {
    employeeCount = c;
    return true;
  }
}
std::string Vendor::getName() {
  return name;
}
std::string Vendor::getAddress() {
  return address;
}
std::string Vendor::getEmail() {
  return email;
}
std::string Vendor::getSellObject() {
  return sellObject;
}
int Vendor::getEmployeeCount() {
  return employeeCount;
}
