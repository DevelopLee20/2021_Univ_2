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

Car createCar(){
    Car tmp(0,1,"metal");

    return tmp;
}

int main(void){
    Car c;
    c.print();
    c = createCar();
    c.print();

    return 0;
}