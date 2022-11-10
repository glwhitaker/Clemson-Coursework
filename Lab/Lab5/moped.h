//Sam Ogle
//CPSC 1021
//10/10/22
//Description: Vehicle class header file

#ifndef MOPED_H
#define MOPED_H

class Moped {
    private:
        std::string make;
        std::string model;
        int year;
        bool twoSeater;
        bool basket;
    public:
        Moped();
        bool setMake(std::string);
        bool setModel(std::string);
        bool setYear(int);
        bool setTwoSeater(bool);
        bool setBasket(bool);
        std::string getMake();
        std::string getModel();
        int getYear();
        std::string getTwoSeater();
        std::string getBasket();
};

#endif
