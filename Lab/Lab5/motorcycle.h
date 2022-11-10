#ifndef CAR_H
#define CAR_H

using namespace std;

class Motorcycle {
    private:
        string make;
        string model;
        int year;
        bool hasRadio;
        string color;
    public:
        Motorcycle();
        Motorcycle(string, string, int, bool, string);

        void setMake(string);
        string getMake();

        void setModel(string);
        string getModel();

        void setYear(int);
        int getYear();

        void setHasRadio(bool);
        std::string getHasRadio();

        void setColor(string);
        string getColor();
};

#endif