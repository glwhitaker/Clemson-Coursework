// Grayson Whitaker
// CPSC 1021
// 10/21/2022
// This file includes method implementation for Date class

#include <string>
#include <iomanip>
#include <sstream>
#include "Date.h"

// const array of strings to store names of months by number
std::string const Date::MONTHS[12] = 
    {"JANUARY", "FEBRUARY", "MARCH",
    "APRIL", "MAY", "JUNE", "JULY",
    "AUGUST", "SEPTEMBER", "OCTOBER",
    "NOVEMBER", "DECEMBER"};

int Date::getMonth() const{
    return month;
}

void Date::setMonth(int m){
    month = m;
}

int Date::getDay() const{
    return day;
}

void Date::setDay(int d){
    day = d;
}

int Date::getYear() const{
    return year;
}

void Date::setYear(int y){
    year = y;
}

// print function to create string of a Date object using stringstreams
std::string Date::print(){
    std::stringstream dateString;
    dateString << std::left << std::setw(10) << MONTHS[month - 1] << std::setw(3) << day << std::setw(5) << year;
    return dateString.str();
}

// compare function to return true if d1 is earlier than d2, false if otherwise
bool Date::compare(Date const d1, Date const d2){
    if(d1.getYear() < d2.getYear()) return true;
    else if((d1.getYear() == d2.getYear()) && (d1.getMonth() < d2.getMonth())) return true;
    else if((d1.getYear() == d2.getYear()) && (d1.getMonth() == d2.getMonth()) && (d1.getDay() < d2.getDay())) return true;
    else return false;
}