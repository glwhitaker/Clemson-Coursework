// Grayson Whitaker
// CPSC 1021
// 9/26/2022
// This file contains main function to calculate a patient's total charges
// after being treated base on user input

#include <iostream>
#include <iomanip>
#include "Patient.h"

using namespace std;

int main(void){
    cout << fixed << showpoint << setprecision(2);
    // describe what program does
    cout << "This program will calculate a patient's hospital charges.\n\n";
    // inititalize needed variables
    int d;
    double r, s, m;
    char p;
    // instantiate Patient class object myPatient
    Patient myPatient;
    // prompt user to enter patient type, validate input, and set myPatient member
    cout << "Enter I for in-patient or O for out-patient: ";
    cin >> p;
    while(p != 'I' && p != 'O'){
        cout << "Please enter a valid choice (I or O): ";
        cin >> p;
    }
    myPatient.setPatientType(p);
    // if in-patient
    if(myPatient.getPatientType() == 'I'){
        // prompt for number of days and set myPatient member
        cout << "Number of days in the hospital: ";
        cin >> d;
        myPatient.setDays(d);
        // prompt for room rate and set myPatient member
        cout << "Daily room rate ($): ";
        cin >> r;
        myPatient.setRate(r);
    }
    // prompt for lab fees and set myPatient member
    cout << "Lab fees and other service charges ($): ";
    cin >> s;
    myPatient.setServices(s);
    // prompt for medication charges and set myPatient member
    cout << "Medication charges ($): ";
    cin >> m;
    myPatient.setMedication(m);
    // calculate total charges and display to user
    cout << "\n Your total hospital bill is $" << myPatient.calcTotalCharges() << endl;


    return 0;
}