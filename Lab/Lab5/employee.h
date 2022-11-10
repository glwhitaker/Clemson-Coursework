// This file contains class definition for Employee class

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee{
    private:
        std::string name;
        std::string address;
        std::string email;
        int employeeNumber;
        int hireYear;
    public:
        Employee();
        Employee(std::string n, std::string a, std::string e, int en, int y);
        std::string getName();
        std::string getAddress();
        std::string getEmail();
        int getEmployeeNumber();
        int getHireYear();
        bool setName(std::string n);
        bool setAddress(std::string a);
        bool setEmail(std::string e);
        bool setEmployeeNumber(int en);
        bool setHireYear(int y);
};
#endif