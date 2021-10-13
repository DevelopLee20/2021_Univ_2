#include <iostream>
#include "실습13_Point.h"
using namespace std;

Point::Point() : x(0), y(0){

}

Point::Point(int a, int b) : x(a), y(b){

}

void Point::print(){
    cout << "(" << x << ", " << y << ")\n";
}