// Grayson Whitaker
// CPSC 1021
// 9/9/2022
// This program determines points awarded to students
// based on the number of times they rode bikes to
// campus

#include <iostream>

using namespace std;

int main(void){
    // variables
    int bikeRides, points;
    // display prompt
    cout << "Enter number of bike rides this semester: ";
    cin >> bikeRides;
    // validate user input
    while(bikeRides < 0){
        cout << "Please enter valid number of rides: ";
        cin >> bikeRides;
    }
    // determine number of points based on bike rides
    switch(bikeRides){
        case 0:
            points = 0;
            break;
        case 1:
            points = 3;
            break;
        case 2:
            points = 10;
            break;
        case 3:
            points = 15;
            break;
        case 4:
            points = 30;
            break;
        default:
            points = 50;
            break;
    }
    // display points earned
    cout << "You earned " << points << " points this semester\n";

    return 0;
}