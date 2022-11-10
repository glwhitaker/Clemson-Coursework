//Sam Ogle
//CPSC 1021
//10/10/22
//Description: Customer class definitions

#include <iostream>
#include <string>
#include "student.h"


Student::Student(){
    name = "N/A";
    address = "N/A";
    email = "N/A";
    age = 0;
    studentIDNum = 10000000;
}

bool Student::setName(std::string n) {
    if (n != "") {
        name = n;
        return true;
    }
    else {
        return false;
    }
}

bool Student::setAddress(std::string a) {
    if (a != "") {
        address = a;
        return true;
    }
    else {
        return false;
    }
}

bool Student::setEmail(std::string e) {
    if (e != "") {
        email = e;
        return true;
    }
    else {
        return false;
    }
}

bool Student::setAge(int studentAge) {
    if (studentAge >= 18) {
        age = studentAge;
        return true;
    }
    else {
        return false;
    }
}

bool Student::setStudentIDNum(int IDNum) {
    if (IDNum > 0) {
        studentIDNum = IDNum;
        return true;
    }
    else {
        return false;
    }
}

std::string Student::getName () {
    return name;
}

std::string Student::getAddress() {
    return address;
}

std::string Student::getEmail() {
    return email;
}

int Student::getAge() {
    return age;
}

int Student::getStudentIDNum() {
    return studentIDNum;
}