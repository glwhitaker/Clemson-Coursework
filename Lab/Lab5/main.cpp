// Grayson Whitaker
// CPSC 1021
// 10/14/2022
// main function to take user information and print invoice for
// parking permit

#include <iostream>
#include <string>
#include "employee.h"
#include "vendor.h"
#include "visitor.h"
#include "student.h"
#include "lowEmission.h"
#include "car.h"
#include "motorcycle.h"
#include "moped.h"
#include "Invoice.h"

using namespace std;

int main(void){
    // variables needed for user choice
    int userChoice;

    Invoice myInvoice;
    string invoice = "\nCustomer Invoice: \n\n";
    // prompt user to enter customer type and validate input
    cout << "\nCustomer Type:\n\n";
    cout << "\t1. Employee\n";
    cout << "\t2. Student\n";
    cout << "\t3. Visitor\n";
    cout << "\t4. Vendor\n";
    cout << "\nPlease enter type: ";
    cin >> userChoice;
    while(userChoice < 1 || userChoice > 4){
        cout << "Please enter a valid choice: ";
        cin >> userChoice;
    }

    string n, a, e;
    // take data for all people
    cout << "\nEnter the following data:\n\n";
    cin.ignore();

    cout << "Name: ";
    getline(cin, n);

    cout << "Address: ";
    getline(cin, a);

    cout << "E-mail: ";
    getline(cin, e);

    // employee class input and validation
    if(userChoice == 1){
        Employee myEmployee;
        int en, y;

        while(!myEmployee.setName(n)){
            cout << "Re-enter name: ";
            getline(cin, n);
        }
        while(!myEmployee.setAddress(a)){
            cout << "Re-enter address: ";
            getline(cin, a);
        }
        while(!myEmployee.setEmail(e)){
            cout << "Re-enter e-mail: ";
            getline(cin, e);
        }

        cout << endl;

        cout << "8-digit employee number: ";
        cin >> en;
        while(!myEmployee.setEmployeeNumber(en)){
            cout << "Enter a valid response: ";
            cin >> en;
        }
        cout << "What year were you hired by Clemson?: ";
        cin >> y;
        while(!myEmployee.setHireYear(y)){
            cout << "Enter a valid response: ";
            cin >> y;
        }

        // pass object to invoice
        invoice += myInvoice.invoicePrintOut(myEmployee);
    }

    // student class input and validation
    else if(userChoice == 2){
        Student myStudent;
        int IDNum, studentAge;

        while(!myStudent.setName(n)){
            cout << "Enter a valid response: ";
            cin >> n;
        }

        while(!myStudent.setAddress(a)){
            cout << "Enter a valid response: ";
            cin >> a;
        }

        while(!myStudent.setEmail(e)){
            cout << "Enter a valid response: ";
            cin >> e;
        }

        cout << "8-digit student number: ";
        cin >> IDNum;
        while(!myStudent.setStudentIDNum(IDNum)){
            cout << "Enter a valid response: ";
            cin >> IDNum;
        }

        cout << "Age: ";
        cin >> studentAge;
        while(!myStudent.setAge(studentAge)){
            cout << "Enter a valid response: ";
            cin >> studentAge;
        }

        // pass object to invoice
        invoice += myInvoice.invoicePrintOut(myStudent);
    }

    // visitor class input and validation
    else if(userChoice == 3){
        Visitor myVisitor;

        string r, isAInput;
        bool isA;

        myVisitor.setName(n);
        myVisitor.setAddress(a);
        myVisitor.setEmail(e);

        cout << endl;

        cout << "Reason for visit: ";
        getline(cin, r);
        myVisitor.setReason(r);

        cout << "Are you Clemson alumni? (yes/no): ";
        cin >> isAInput;
        while(isAInput != "yes" && isAInput != "no"){
            cout << "Enter a valid response: ";
            cin >> isAInput;
        }
        if(isAInput == "yes") isA = true;
        else isA = false;

        myVisitor.setIsAlumni(isA);

        // pass object to invoice
        invoice += myInvoice.invoicePrintOut(myVisitor);
    }

    // vendor class input and validation
    else if(userChoice == 4){
        Vendor myVendor;
        string s;
        int c;

        while(!myVendor.setName(n)){
            cout << "Re-enter name: ";
            getline(cin, n);
        }
        while(!myVendor.setAddress(a)){
            cout << "Re-enter address: ";
            getline(cin, a);
        }
        while(!myVendor.setEmail(e)){
            cout << "Re-enter e-mail: ";
            getline(cin, e);
        }

        cout << endl;

        cout << "What do you sell?: ";
        getline(cin, a);
        while(!myVendor.setSellObject(a)){
            cout << "Enter a valid response: ";
            getline(cin, s);
        }

        cout << "Employee count: ";
        cin >> c;
        while(!myVendor.setEmployeeCount(c)){
            cout << "Enter a valid response: ";
            cin >> c;
        }

        // pass object to invoice
        invoice += myInvoice.invoicePrintOut(myVendor);
    }

    // prompt user for vehicle type and validate input
    cout << "\nVehicle Type:\n\n";
    cout << "\t1. Car\n";
    cout << "\t2. Low-emission vehicle\n";
    cout << "\t3. Motorcycle\n";
    cout << "\t4. Moped scooter\n";
    cout << "\nPlease enter type: ";
    cin >> userChoice;
    while(userChoice < 1 || userChoice > 4){
        cout << "Please enter a valid choice: ";
        cin >> userChoice;
    }

    string m, md;
    int y;

    // take input for all vehicles
    cout << "\nEnter the following data:\n\n";
    cin.ignore();

    cout << "Make: ";
    getline(cin, m);
    
    cout << "Model: ";
    getline(cin, md);

    cout << "Year: ";
    cin >> y;

    // car class input and validation
    if(userChoice == 1){
        Car myCar;

        string l;
        int n;

        while(!myCar.setMake(m)){
            cout << "Please re-enter make: ";
            getline(cin, m);
        }

        while(!myCar.setModel(md)){
            cout << "Please re-enter model: ";
            getline(cin, md);
        }

        while(!myCar.setYear(y)){
            cout << "Please re-enter year: ";
            cin >> y;
        }

        cout << endl;
        cin.ignore();

        cout << "License plate number: ";
        getline(cin, l);
        while(!myCar.setLicensePlate(l)){
            cout << "Enter a valid response: ";
            getline(cin, l);
        }

        cout << "Number of doors: ";
        cin >> n;
        while(!myCar.setNumDoors(n)){
            cout << "Enter a valid response: ";
            cin >> n;
        }
        // $20 charge for larger cars
        if(n > 2) myInvoice.setServiceCharge(20);

        // pass object to invoice
        invoice += myInvoice.invoicePrintOut(myCar);
    }

    // lowEmission class input and validation
    else if(userChoice == 2){
        lowEmission myLowEmission;

        string evInput;
        bool ev;
        double mpc, mpg;

        while(!myLowEmission.setMake(m)){
            cout << "Please re-enter make: ";
            getline(cin, m);
        }

        while(!myLowEmission.setModel(md)){
            cout << "Please re-enter model: ";
            getline(cin, md);
        }

        while(!myLowEmission.setYear(y)){
            cout << "Please re-enter year: ";
            cin >> y;
        }

        cout << endl;

        cout << "Is your vehicle electric? (yes/no): ";
        cin >> evInput;
        while(evInput != "yes" && evInput != "no"){
            cout << "Enter a valid response: ";
            cin >> evInput;
        }
        if(evInput == "yes") ev = true;
        else ev = false;

        myLowEmission.setElectricVehicle(ev);

        if(ev == true){
            cout << "Miles per charge: ";
            cin >> mpc;
            while(!myLowEmission.setMilesPerCharge(mpc)){
                cout << "Enter a valid response: ";
                cin >> mpc;
            }
        }
        else{
            cout << "Miles per gallon: ";
            cin >> mpg;
            while(!myLowEmission.setMilesPerGallon(mpg)){
                cout << "Enter a valid response: ";
                cin >> mpg;
            }
        }
        // discount 20% if user drives low emission vehicle
        myInvoice.setDiscount(0.2);

        // pass object to invoice
        invoice += myInvoice.invoicePrintOut(myLowEmission);
    }

    // motorcycle class input and validation
    else if(userChoice == 3){
        Motorcycle myMotorcycle;

        string c, hasRINput;
        bool hasR;

        myMotorcycle.setMake(m);
        myMotorcycle.setModel(md);
        myMotorcycle.setYear(y);

        cout << endl;
        cin.ignore();

        cout << "Color: ";
        getline(cin, c);
        myMotorcycle.setColor(c);

        cout << "Does your motorcycle have radio? (yes/no): ";
        cin >> hasRINput;
        while(hasRINput != "yes" && hasRINput != "no"){
            cout << "Enter a valid response: ";
            cin >> hasRINput;
        }
        if(hasRINput == "yes") hasR = true;
        else hasR = false;

        myMotorcycle.setHasRadio(hasR);

        // pass object to invoice
        invoice += myInvoice.invoicePrintOut(myMotorcycle);
    }

    // moped class input and validation
    else if(userChoice == 4){
        Moped myMoped;

        bool mopedSeats, baskets;
        string seatsInput, basketsInput;

        myMoped.setMake(m);
        myMoped.setModel(md);
        myMoped.setYear(y);


        cout << endl;
        cin.ignore();

        cout << "Two seater? (yes/no): ";
        getline(cin, seatsInput);
        while(seatsInput != "yes" && seatsInput != "no"){
            cout << "Enter a valid response: ";
            cin >> seatsInput;
        }
        if(seatsInput == "yes") mopedSeats = true;
        else mopedSeats = false;

        myMoped.setTwoSeater(mopedSeats);

        cout << "Basket? (yes/no): ";
        getline(cin, basketsInput);
        while(basketsInput != "yes" && basketsInput != "no"){
            cout << "Enter a valid response: ";
            cin >> basketsInput;
        }
        if(basketsInput == "yes") baskets = true;
        else baskets = false;

        myMoped.setBasket(baskets);

        // pass object to invoice
        invoice += myInvoice.invoicePrintOut(myMoped);
    }

    // prompt for permit selection and validation
    cout << "\nPermit Selection:\n\n";
    cout << "\t1. Annual Permit - $275\n";
    cout << "\t2. Semester Permit - $150\n";
    cout << "\t3. Daily Permit - $50\n";
    cout << "\nPlease enter permit type selection: ";
    cin >> userChoice;
    while(userChoice < 1 || userChoice > 3){
        cout << "Please enter a valid choice: ";
        cin >> userChoice;
    }
    
    // annual permit
    if(userChoice == 1){
        myInvoice.setPermitPrice(275);
        myInvoice.setPermitType("Annual");
    }

    // semester permit
    else if(userChoice == 2){
        myInvoice.setPermitPrice(150);
        myInvoice.setPermitType("Semester");
    }

    // daily permit
    else if(userChoice == 3){
        myInvoice.setPermitPrice(50);
        myInvoice.setPermitType("Daily");
    }

    // print out invoice
    invoice += myInvoice.invoicePrintOut();
    cout << invoice  << endl;
    return 0;
}