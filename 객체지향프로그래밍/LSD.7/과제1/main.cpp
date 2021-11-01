#include "Car.h"    // Car.h 헤더파일을 include

int main(void){
    cout << "지금까지 생성된 자동차 수 = " << Car::count << endl;   // 현재 생성된 객체는 0개
    createCar().print();    // createCar()에 의해서 실제 객체가 생성되고, 이 문장을 수행한 이후에는 객체가 소멸된다.

    cout << "지금까지 생성된 자동차 수 = " << Car::count << endl;   // 따라서 현재 생성된 객체는 1개이지만 위의 문장에서 소멸했으므로 0

    Car c1(100,0,"blue");   // 객체 총 1개 생성
    Car c2(0,0,"white");    // 객체 총 2개 생성

    cout << "지금까지 생성된 자동차 수 = " << Car::count << endl;   // 생성된 객체는 총 2개

    Car c3(0,0,"red");      // 객체 총 3개 생성

    // 생성된 객체는 총 3개이고, static 변수이므로 count 값을 모든 객체가 공유한다.
    cout << "지금까지 생성된 자동차 수 = " << c1.count << endl;
    cout << "지금까지 생성된 자동차 수 = " << c2.count << endl;

    return 0;
}