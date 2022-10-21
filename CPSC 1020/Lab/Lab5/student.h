//Sam Ogle
//CPSC 1021
//10/10/22
//Description: Customer class header file

#ifndef STUDENT_H
#define STUDENT_H

class Student{
     private:
        std::string name;
        std::string address;
        std::string email;
        int age;
        int studentIDNum;
    public:
        Student();
        bool setName(std::string n);
        bool setAddress(std::string a);
        bool setEmail(std::string e);
        bool setAge(int);
        bool setStudentIDNum(int);
        std::string getName();
        std::string getAddress();
        std::string getEmail();
        int getAge();
        int getStudentIDNum();
};

#endif