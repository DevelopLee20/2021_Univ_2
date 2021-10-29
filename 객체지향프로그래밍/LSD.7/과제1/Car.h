#include <iostream>
#include <string>
using namespace std;

class Car{
    int speed;
    int gear;
    string color;

public:
    static int count;

    Car(int s=0, int g=1, string c="white");
    ~Car();
    int getSpeed();
    void setSpeed(int speed);
    void print();
};

Car createCar();