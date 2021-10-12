#include <iostream>
#include "실습13_Point.h"

class Circle{
private:
    int radius;
    Point center;

public:
    Circle();
    Circle(int r);
    Circle(Point p, int r);
    Circle(int x, int y, int r);
    void print();
};