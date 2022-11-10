#pragma once

class Car {
  private:
    std::string make;
    std::string model;
    std::string licensePlate;
    int year;
    int numDoors;
  public:
    Car();
    Car(std::string ma, std::string mo, std::string l, int y, int n);
    std::string getMake();
    std::string getModel();
    std::string getLicensePlate();
    int getYear();
    int getNumDoors();
    bool setMake(std::string m);
    bool setModel(std::string md);
    bool setLicensePlate(std::string l);
    bool setYear(int y);
    bool setNumDoors(int n);
};
