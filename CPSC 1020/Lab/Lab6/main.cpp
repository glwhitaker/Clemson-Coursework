// Grayson Whitaker
// CPSC 1021
// 10/21/2022
// This file includes a main function which reads dates from an input file, sorts the dates from earliest to latest,
// and outputs them to an output file using the names of the months instead of the number.

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include "Date.h"

using namespace std;

// take command line arguments
int main(int argc, char *argv[]){
    // instantiate Date object
    Date myDate;

    // initialize an input file
    ifstream readDateFile;

    // initialize 'number' to be used for number of dates included in file
    int number;

    // open file designated by argv[1]
    readDateFile.open(argv[1]);

    // if file is open, read value which designates the number of dates included in input file and store value in 'number'
    if(readDateFile.is_open()){
        readDateFile >> number;
    }

    // initialize vector of Date objects
    vector<Date> vectorDate;

    // create 'number' vectors of Date objects
    for(int i = 0; i < number; i++){
        vectorDate.push_back(myDate);
    }
    
    //initialize integers to store month, date, and year from input file
    int m, d, y;

    // if file is open assign values in input file to variables in each Date object
    if(readDateFile.is_open()){
        for(int i = 0; i < number; i++){
            readDateFile >> m;
            vectorDate[i].setMonth(m);
            readDateFile >> d;
            vectorDate[i].setDay(d);
            readDateFile >> y;
            vectorDate[i].setYear(y);
        }
    }

    // close input file, no longer needed
    readDateFile.close();

    // use sort function by passing each Date object into Date::compare funciton
    sort(vectorDate.begin(), vectorDate.end(), Date::compare);

    // initialize output file
    ofstream writeDateFile;

    // open output file designated by argv[2]
    writeDateFile.open(argv[2]);

    // if file is open use Date::print function to write each Date object into output file
    if(writeDateFile.is_open()){
        for(int i = 0; i < number; i++){
            writeDateFile << vectorDate[i].print() << endl;
        }
    }

    // close output file
    writeDateFile.close();

    return 0;
}