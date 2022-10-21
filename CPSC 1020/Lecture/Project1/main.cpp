// Grayson Whitaker
// CPSC 1020
// 9/30/2022
// This file contains main function for Project 1 which is a isolation self-assessment tool
// to provide user with isolation times based off certain criteria such as test results and vaccination status

#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"
#include "calcDays.h"

using namespace std;

int main(void){
    // initialize starting variables
    string testResult;
    int d, m, y;
    char ch;
    // prompt user for test results and validate input
    cout << "\nTest result (positive/negative): ";
    cin >> testResult;
    while(testResult != "positive" && testResult != "negative"){
        cout << "Please enter a valid response: ";
        cin >> testResult;
    }
    // if positive
    if(testResult == "positive"){
        // instantiate Date object to record date positive
        Date datePositive;
        // prompt for date positive and take input, ignoring non digits
        cout << "Date tested positive (MM/DD/YYYY): ";
        while(cin.get(ch)){
            if(isdigit(ch)){
                cin.putback(ch);
                cin >> m;
                datePositive.setMonth(m);
                break;
            }
        }
        while(cin.get(ch)){
            if(isdigit(ch)){
                cin.putback(ch);
                cin >> d;
                datePositive.setDay(d);
                break;
            }
        }
        while(cin.get(ch)){
            if(isdigit(ch)){
                cin.putback(ch);
                cin >> y;
                datePositive.setYear(y);
                break;
            }
        }
        cout << "Length of isolation: 5 days" << endl << endl;
    }
    // if negative
    else{
        // initlialize new needed variables
        string exposed;
        // prompt user for exposed to positive case and validate input
        cout << "Exposed to positive case (yes/no): ";
        cin >> exposed;
        if(exposed != "yes" && exposed != "no"){
            cout << "Please enter a valid response: ";
            cin >> exposed;
        }
        // if exposed
        if(exposed == "yes"){
            // instantiate Date object to record date exposed
            Date dateExposed;
            // prompt for date exposed and take input, ignoring non digits
            cout << "Date exposed to positive case (MM/DD/YYYY): ";
            while(cin.get(ch)){
                if(isdigit(ch)){
                    cin.putback(ch);
                    cin >> m;
                    dateExposed.setMonth(m);
                    break;
                }
            }
            while(cin.get(ch)){
                if(isdigit(ch)){
                    cin.putback(ch);
                    cin >> d;
                    dateExposed.setDay(d);
                    break;
                }
            }
            while(cin.get(ch)){
                if(isdigit(ch)){
                    cin.putback(ch);
                    cin >> y;
                    dateExposed.setYear(y);
                    break;
                }
            }
            // initialize varible for second vaccination
            string secondVacc;
            // prompt for second vaccination and validate input
            cout << "Second vaccination dose received (yes/no): ";
            cin >> secondVacc;
            while(secondVacc != "yes" && secondVacc != "no"){
                cout << "Please enter a valid response: ";
                cin >> secondVacc;
            }
            // if second vaccination
            if(secondVacc == "yes"){
                // instantiate date object to record date of second dose
                Date dateSecondDose;
                // prompt for date of second dose and take input, ignoring non digits
                cout << "Date second vaccination dose recieved (MM/DD/YYYY): ";
                while(cin.get(ch)){
                    if(isdigit(ch)){
                        cin.putback(ch);
                        cin >> m;
                        dateSecondDose.setMonth(m);
                        break;
                    }
                }
                while(cin.get(ch)){
                    if(isdigit(ch)){
                        cin.putback(ch);
                        cin >> d;
                        dateSecondDose.setDay(d);
                        break;
                    }
                }
                while(cin.get(ch)){
                    if(isdigit(ch)){
                        cin.putback(ch);
                        cin >> y;
                        dateSecondDose.setYear(y);
                        break;
                    }

                }
                // if 2 weeks or more have passed since second vaccination, display isolation results
                if(calcDays(dateExposed, dateSecondDose) < 14){
                    cout << "Vaccination status at time of exposure: not full vaccinated" << endl;
                    cout << "Length of isolation: 10 days" << endl << endl;
                }
                // if less than two weeks have passed since second vaccination, display isolation results
                else{
                    cout << "Vaccination status at time of exposure: fully vaccinated" << endl;
                    cout << "Length of isolation: 5 days" << endl << endl;
                }

            }
            // if no second vaccination
            else{
                // display isolation results
                cout << "Vaccination status at time of exposure: not full vaccinated" << endl;
                cout << "Length of isolation: 10 days" << endl << endl;
            }

        }
        // if not exposed
        else{
            // display isolation results
            cout << "Length of isolation: 0 days" << endl << endl;
        }
    }
    return 0;
}