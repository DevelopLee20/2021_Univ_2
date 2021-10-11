#include <iostream>
#include <string>
using namespace std;

class Car{
public:
    int speed;
    int gear;
    string color;

    void speedUp(){
        speed += 10;
    }

    void speedDown(){
        speed -= 10;
    }

    void show(){
        cout << "================" << endl;
        cout << "속도: " << speed << endl;
        cout << "기어: " << gear << endl;
        cout << "색상: " << color << endl;
        cout << "================" << endl;
    }
};

int main(void){
    Car *dynCar = new Car;

    dynCar->speed = 100;
    dynCar->gear = 2;
    dynCar->color = "green";

    dynCar->speedUp();
    dynCar->show();

    delete dynCar;

    return 0;
}