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

    void print();
};

void Car::print(){
    cout << "속도: " << speed << "기어: " << gear << "색상: " << color << endl;
}

int main(void){
    Car objArray[3] = {
        Car(0,1,"white"),
        Car(0,1,"red"),
        Car(0,1,"blue"),
    };

    for(int i=0; i<3; i++){
        (objArray+i)->print();
    }

    Car *p = objArray;

    for(int i=0; i<3; i++){
        p->print();
        p++;
    }

    return 0;
}