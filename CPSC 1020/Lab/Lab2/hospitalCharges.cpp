// Grayson Whitaker
// CPSC 1021
// 9/12/2022
// This program calculates a patient's total charges after
// being treated based on whether they were an inpatient or
// outpatient

#include <iostream>
#include <iomanip>
#include "validateUserInput.h"
#include "calcTotalCharges.h"

using namespace std;

int main(void){
    cout << fixed << showpoint << setprecision(2);

    // describe what program does
    cout << "This program will calculate a patient's hospital charges.\n\n";

    // initialize needed variable patientType
    char patientType;

    // prompt user to enter patientType and validate input
    cout << "Enter I for in-patient or O for out-patient: ";
    cin >> patientType;
    while(patientType != 'I' && patientType != 'O'){
        cout << "Please enter a valid choice (I or O): ";
        cin >> patientType;
    }

    // initialize needed variables for total charges
    double numDays, roomRate, hospServices, medCharges, totalCharges;

    // if in-patient
    if(patientType == 'I'){
        // prompt for numDays
        cout << "Number of days in the hospital: ";
        cin >> numDays;
        while(!validateUserInput(numDays)){
          cout << "Please enter a valid number: ";
          cin >> numDays;
        }

        // prompt for roomRate
        cout << "Daily room rate ($): ";
        cin >> roomRate;
        while(!validateUserInput(roomRate)){
          cout << "Please enter a valid number: ";
          cin >> roomRate;
        }
    }

    // prompt for hospServices
    cout << "Lab fees and other service charges ($): ";
    cin >> hospServices;
    while(!validateUserInput(hospServices)){
      cout << "Please enter a valid number: ";
      cin >> hospServices;
    }

    // prompt for medCharges
    cout << "Medication charges ($): ";
    cin >> medCharges;
    while(!validateUserInput(medCharges)){
      cout << "Please enter a valid number: ";
      cin >> medCharges;
    }
    // calc total charges for either in-patient or out-patient
    if(patientType == 'I'){
        totalCharges = calcTotalCharges(numDays, roomRate, hospServices, medCharges);
    }
    else{
        totalCharges = calcTotalCharges(hospServices, medCharges);
    }

    // display total charges
    cout << "\nYour total hospital bills is $" << totalCharges << endl;

    return 0;
}
