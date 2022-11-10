// This file contains class definition for lowEmission class

#ifndef LOW_EMISSION_H
#define LOW_EMISSION_H

class lowEmission{
    private:
        std::string make;
        std::string model;
        int year;
        bool electricVehicle;
        double milesPerCharge;
        double milesPerGallon;
    public:
        lowEmission();
        lowEmission(std::string m, std::string md, int y, bool ev, double mpc, double mpg);
        std::string getMake();
        std::string getModel();
        int getYear();
        std::string getElectricVehicle();
        double getMilesPerCharge();
        double getMilesPerGallon();
        bool setMake(std::string m);
        bool setModel(std::string md);
        bool setYear(int y);
        bool setElectricVehicle(bool ev);
        bool setMilesPerCharge(double mpc);
        bool setMilesPerGallon(double mpg);
};
#endif