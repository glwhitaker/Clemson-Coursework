// Grayson Whitaker
// CPSC 1021
// 10/21/2022
// This file includes class definition for Date class

#ifndef DATE_H
#define DATE_H

class Date{
    private:
        int month {1};
        int day {1};
        int year {1900};
    public:
        static const std::string MONTHS[12];
        Date() = default;
        Date(int m, int d, int y) : month {m}, day {d}, year {y} {};
        int getMonth() const;
        void setMonth(int m);
        int getDay() const;
        void setDay(int d);
        int getYear() const;
        void setYear(int y);
        std::string print();
        static bool compare(Date const d1, Date const d2);
};

#endif