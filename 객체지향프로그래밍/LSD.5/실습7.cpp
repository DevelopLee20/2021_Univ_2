#include <iostream>
#include <string>
using namespace std;

class Car{
private:
    int speed;
    int gear;
    string color;

public:
    int getSpeed();
    void setSpeed(int s);
    int getGear();
    void setGear(int g);
    string getColor();
    void setColor(string c);
};

int Car::getSpeed(){
    return speed;
}

void Car::setSpeed(int s){
    speed = s;
}

int Car::getGear(){
    return gear;
}

void Car::setGear(int g){
    gear = g;
}

string Car::getColor(){
    return color;
}

void Car::setColor(string c){
    color = c;
}

int main(void){
    Car myCar;

    myCar.setSpeed(100);
    myCar.setGear(3);
    myCar.setColor("red");

    cout << "차의 속도: " << myCar.getSpeed() << endl;
    cout << "차의 기어: " << myCar.getGear() << endl;
    cout << "차의 색상: " << myCar.getColor() << endl;

    return 0;
}