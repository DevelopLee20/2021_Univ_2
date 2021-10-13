#include <iostream>
using namespace std;

class Car{
private:
    int speed;
    int gear;
    string color;

public:
    int getSpeed(){
        return speed;
    }

    void setSpeed(int s){
        speed = s;
    }

    int getGear(){
        return gear;
    }

    void setGear(int g){
        gear = g;
    }

    string getColor(){
        return color;
    }

    void setColor(string c){
        color = c;
    }
};

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