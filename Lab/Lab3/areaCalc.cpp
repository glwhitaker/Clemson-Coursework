#include <iostream>
#include <iomanip>
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Trapezoid.h"

using namespace std;

int main(void){
    cout << fixed << showpoint << setprecision(1);
    // display menu
    int userChoice;
    cout << "1 -- circle\n";
    cout << "2 -- square\n";
    cout << "3 -- rectangle\n";
    cout << "4 -- trapezoid\n";
    cout << "5 -- quit\n";
    // take and validate userChoice
    cin >> userChoice;
    while(userChoice < 1 || userChoice > 5){
        cout << "Please enter a valid choice: ";
        cin >> userChoice;
    }
    // determine shape from userChoice
    double area, r, b, h;
    switch(userChoice){
        case 1:
            Circle circle1;
            cout << "Radius: ";
            cin >> r;
            while(!circle1.setRadius(r)){
                cout << "Please enter a valid number: ";
                cin >> r;
            }
            area = circle1.calcArea();
            cout << "Area: " << area << endl;
            break;
        case 2:
            Square square1;
            cout << "Side: ";
            cin >> b;
            while(!square1.setSide(b)){
                cout << "Please enter a valid number: ";
                cin >> b;
            }
            area = square1.calcArea();
            cout << "Area: " << area << endl;
            break;
        case 3:
            Rectangle rectangle1;
            cout << "Length: ";
            cin >> b;
            while(!rectangle1.setLength(b)){
                cout << "Please enter a valid number: ";
                cin >> b;
            }
            cout << "Width: ";
            cin >> h;
            while(!rectangle1.setWidth(h)){
                cout << "Please enter a valid number: ";
                cin >> h;
            }
            area = rectangle1.calcArea();
            cout << "Area: " << area << endl;
            break;
        case 4:
            Trapezoid trapezoid1;
            cout << "Base1: ";
            cin >> b;
            while(!trapezoid1.setBase1(b)){
                cout << "Please enter a valid number: ";
                cin >> b;
            }
            cout << "Base2: ";
            cin >> b;
            while(!trapezoid1.setBase2(b)){
                cout << "Please enter a valid number: ";
                cin >> b;
            }
            cout << "Height: ";
            cin >> h;
            while(!trapezoid1.setHeight(h)){
                cout << "Please enter a valid number: ";
                cin >> h;
            }
            area = trapezoid1.calcArea();
            cout << "Area: " << area << endl;
            break;
        case 5:
            exit(0);
    }

    return 0;
}
