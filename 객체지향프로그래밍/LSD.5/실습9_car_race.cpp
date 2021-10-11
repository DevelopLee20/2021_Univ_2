#include "실습9_car_race.h"

int Car::geteSpeed(){
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

void Car::speedup(){
    speed += 10;
}

void Car::speedDown(){
    speed -= 10;
}

void Car::init(int s, int g, string c){
    speed = s;
    gear = g;
    color = c;
}

void Car::show(){
    cout << "================" << endl;
    cout << "속도: " << speed << endl;
    cout << "기어: " << gear << endl;
    cout << "색상: " << color << endl;
    cout << "================" << endl;
}