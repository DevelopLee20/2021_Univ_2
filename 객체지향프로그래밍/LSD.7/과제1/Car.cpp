#include "Car.h"

int Car::count = 0;

Car::Car(int s, int g, string c) : speed(s), gear(g), color(c){
    count++;
}

Car::~Car(){
    count--;
}

void Car::print(){
    cout << "속도: " << speed << " 기어: " << gear << " 색상: ";
    cout << color << " 객체수: " << Car::count << endl;
}

Car createCar(){
    Car tmp(0,1,"metal");

    return tmp;
}