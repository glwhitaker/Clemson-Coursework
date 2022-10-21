// Grayson Whitaker
// CPSC 1021
// 9/9/2022
// This program calculates and displays the area of
// three different objects based on user input

#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
    // manip stream
    cout << fixed << showpoint << setprecision(2);
    // define PI
    const float PI = 3.14159;
    // variables
    int menuChoice;
    double baseLength, circleRadius, triHeight;
    double squareArea, circleArea, triArea;
    // display menu
    cout << "Program to calculate areas of objects\n";
    cout << "\t1 -- square\n";
    cout << "\t2 -- circle\n";
    cout << "\t3 -- right triangle\n";
    cout << "\t4 -- quit\n";
    // take user input
    cin >> menuChoice;
    // exit if invalid choice
    if(menuChoice < 1 || menuChoice > 4){
        cout << "You entered an invalid choice. Good bye!\n";
        exit(0);
    }
    // determine which shape was chosen
    if(menuChoice == 1){
        cout << "Base length of the square: ";
        cin >> baseLength;
        squareArea = baseLength * baseLength;
        cout << "Area = " << squareArea << endl;
    }
    else if(menuChoice == 2){
        cout << "Radius of the circle: ";
        cin >> circleRadius;
        circleArea = PI * (circleRadius * circleRadius);
        cout << "Area = " << circleArea << endl;
    }
    else if(menuChoice == 3){
        cout << "Base length of the triangle: ";
        cin >> baseLength;
        cout << "Height of the triangle: ";
        cin >> triHeight;
        triArea = (baseLength * triHeight) / 2;
        cout << "Area = " << triArea << endl;
    }
    else{
        exit(0);
    }

    return 0;
}