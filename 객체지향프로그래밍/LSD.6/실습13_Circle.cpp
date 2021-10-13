#include <iostream>
#include "실습13_Point.h"
#include "실습13_Circle.h"
using namespace std;

Circle::Circle() : radius(0), center(0,0){

}

Circle::Circle(int r) : radius(r), center(0,0){
    
}

Circle::Circle(Point p, int r) : radius(r), center(p){
    
}

Circle::Circle(int x, int y, int r) : radius(r), center(x,y){

}

void Circle::print(){
    cout << "중심: ";
    center.print();
    cout << "반지름: " << radius << endl << endl;
}