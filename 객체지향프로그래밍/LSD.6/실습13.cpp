#include <iostream>
#include "실습13_Point.h"
#include "실습13_Circle.h"
using namespace std;

int main(void){
    Point p(5,3);

    Circle c1;
    Circle c2(3);
    Circle c3(p,4);
    Circle c4(9,7,5);

    c1.print();
    c2.print();
    c3.print();
    c4.print();

    return 0;
}