// Grayson Whitaker
// CPSC 1021
// 9/26/2022
// This file contains class defintion for Patient

#ifndef PATIENT_H
#define PATIENT_H

class Patient{
    private:
        int days;
        double rate;
        double services;
        double medication;
        char patientType;
        bool validateInput(int);
        bool validateInput(double);
    public:
        Patient();
        Patient(char, double, double);
        Patient(char, int, double, double, double);
        int getDays();
        bool setDays(int);
        double getRate();
        bool setRate(double);
        double getServices();
        bool setServices(double);
        double getMedication();
        bool setMedication(double);
        char getPatientType();
        bool setPatientType(char);
        double calcTotalCharges();
};

#endif