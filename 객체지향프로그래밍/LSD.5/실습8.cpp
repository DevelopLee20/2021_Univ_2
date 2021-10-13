#include "실습8_car.h"

int main(void){
    Car myCar;

    myCar.setSpeed(80);
    cout << "현재 속도는 " << myCar.getSpeed() << endl;

    return 0;
}