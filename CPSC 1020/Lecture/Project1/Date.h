// Grayson Whitaker
// CPSC 1020
// 9/30/2022
// This file contains class definition for Date class

#ifndef DATE_H
#define DATE_H

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int d, int m, int y);
        bool setDay(int d);
        bool setMonth(int m);
        bool setYear(int y);
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        std::string showDate();
};

#endif
