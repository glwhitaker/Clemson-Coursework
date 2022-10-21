// Grayson Whitaker
// CPSC 1020
// 9/30/2022
// This file conatins function implementation for calcDays

#include <iostream>
#include "Date.h"

int calcDays(const Date& date1, const Date& date2){
    // const array for days of each month
    const int monthDays[12] = {31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    // initialize needed variables
    int dayCount1, dayCount2, daysDiff1, daysDiff2, daysDiff;
    // calc difference between date1 and 01/01/2021
    dayCount1 = 365 * date1.getYear();
    dayCount1 += monthDays[date1.getMonth()];
    dayCount1 += date1.getDay();
    daysDiff1 = dayCount1 - (365 * 2021 + monthDays[1] + 1);
    // calc difference between date1 and 01/01/2021
    dayCount2 = 365* date2.getYear();
    dayCount2 += monthDays[date2.getMonth()];
    dayCount2 += date2.getDay();
    daysDiff2 = dayCount2 - (365 * 2021 + monthDays[1] + 1);
    // calc difference between date1 and date2
    daysDiff = daysDiff1 - daysDiff2;

    return daysDiff;
}