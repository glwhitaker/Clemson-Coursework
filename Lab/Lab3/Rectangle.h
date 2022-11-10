#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{
    private:
        double length;
        double width;
    public:
        double getLength();
        bool setLength(double);
        double getWidth();
        bool setWidth(double);
        double calcArea();
};

#endif
