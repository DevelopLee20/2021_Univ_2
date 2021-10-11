#include "실습9_car_race.h"

int main(void){
    Car car1, car2;

    car1.init(rand()%200, 1, "red");
    car1.show();

    car2.init(rand()%200, 1, "blue");
    car2.show();

    if(car1.geteSpeed() > car2.geteSpeed()){
        cout << "car1이 승리하였습니다" << endl;
    }
    else{
        cout << "car2가 승리하였습니다" << endl;
    }

    return 0;
}