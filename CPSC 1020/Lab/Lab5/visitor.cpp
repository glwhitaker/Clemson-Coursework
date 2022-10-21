#include <iostream>
#include <string>
#include "visitor.h"

using namespace std;

Visitor :: Visitor(string n, string a, string e, string r, bool isA) {
    name = n;
    address = a;
    email = e;
    reason = r;
    isAlumni = isA;
}

void Visitor :: setName(string n) {
    name = n;
}
string Visitor :: getName() {
    return name;
}

void Visitor :: setAddress(string a) {
    address = a;
}
string Visitor :: getAddress() {
    return address;
}

void Visitor :: setEmail(string e) {
    email = e;
}
string Visitor :: getEmail() {
    return email;
}

void Visitor :: setReason(string r) {
    reason = r;
}
string Visitor :: getReason() {
    return reason;
}

void Visitor :: setIsAlumni(bool isA) {
    isAlumni = isA;
}
std::string Visitor :: getIsAlumni() {
    if(isAlumni == true) return "yes";
    else return "no";
}
