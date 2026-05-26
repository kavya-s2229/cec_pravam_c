#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle();
    Rectangle(double l, double w);
    void setdimensions(double l, double w);
    double Area();
    double getPerimeter();
    void display();
};

#endif 


