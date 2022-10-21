// Grayson Whitaker
// CPSC 1020
// 9/30/2022
// This file contains method implementation for all methods in Date class

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

Date::Date(){
    day = 1;
    month = 1;
    year = 2021;
}

Date::Date(int d, int m, int y){
    if(d > 0 && d < 32 && m > 0 && m < 13 && y > 2020 && y < 2023){
        if(d > 28 && m == 2){
            day = 1;
            month = 1;
            year = 1;
        }
        else{
            day = d;
            month = m;
            year = y;
        }
    }
    else{
        day = 1;
        month = 1;
        year = 1;
    }
}

bool Date::setDay(int d){
    if(d > 0 && d < 32){
        day = d;
        return true;
    }
    else return false;
}

bool Date::setMonth(int m){
    if(m > 0 && m < 13){
        month = m;
        return true;
    }
    else return false;
}

bool Date::setYear(int y){
    if(y > 2020 && y < 2023){
        year = y;
        return true;
    }
    else return false;
}

int Date::getDay() const{
    return day;
}

int Date::getMonth() const{
    return month;
}

int Date::getYear() const{
    return year;
}

string Date::showDate(){
    return to_string(getMonth()) + "/" + to_string(getDay()) + "/" + to_string(getYear());
}