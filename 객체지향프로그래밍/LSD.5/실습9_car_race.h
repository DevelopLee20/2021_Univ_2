#include <iostream>
#include <string>
using namespace std;

class Car{
private:
    int speed;
    int gear;
    string color;

public:
    int geteSpeed();
    void setSpeed(int s);
    int getGear();
    void setGear(int g);
    string getColor();
    void setColor(string c);

    void speedup();
    void speedDown();
    void init(int s, int gear, string c);
    void show();
};