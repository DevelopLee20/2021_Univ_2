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
};