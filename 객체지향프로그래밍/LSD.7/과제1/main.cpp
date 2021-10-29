#include "Car.h"

int main(void){
    cout << "지금까지 생성된 자동차 수 = " << Car::count << endl;
    createCar().print();

    cout << "지금까지 생성된 자동차 수 = " << Car::count << endl;

    Car c1(100,0,"blue");
    Car c2(0,0,"white");

    cout << "지금까지 생성된 자동차 수 = " << Car::count << endl;

    Car c3(0,0,"red");

    cout << "지금까지 생성된 자동차 수 = " << c1.count << endl;
    cout << "지금까지 생성된 자동차 수 = " << c2.count << endl;

    return 0;
}