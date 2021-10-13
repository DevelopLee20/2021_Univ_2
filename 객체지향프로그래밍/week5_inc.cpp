#include <iostream>
#include <string>
using namespace std;

class Car{
public: // public, private | default: private
    int speed;
    int gear;
    string color;

    void speedUp(){
        speed += 9;
    }

    void speedDown(){
        speed -= 10;
    }

    void show(){
        cout << speed << endl;
        cout << gear << endl;
        cout << color << endl;
    }
};

int main(void){
    Car myCar;
    Car *pointCar = new Car;

    delete pointCar; // free(pointCar);

    myCar.color = "blue";
    myCar.gear = 3;
    myCar.speed = 10;

    myCar.speedDown();
    myCar.speedUp();

    myCar.show();

    return 0;
}