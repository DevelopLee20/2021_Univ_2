#include <iostream>
#include <string>
using namespace std;

class Car{
    int speed;
    int gear;
    string color;

public:
    Car(int s=0, int g=1, string c="white") : speed(s), gear(g), color(c){
    }

    void print(){
        cout << "속도: " << speed << "기어: " << gear << "색상: " << color << endl;
    }
};

void swapObjects(Car *p1, Car *p2){
    Car tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

int main(void){
    Car red(0,1,"red");
    Car blue(30,2,"blue");

    swapObjects(&red, &blue);
    red.print();
    blue.print();

    return 0;
}