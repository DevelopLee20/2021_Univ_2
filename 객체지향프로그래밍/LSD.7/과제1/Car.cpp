#include "Car.h"    // Car.h를 include

int Car::count = 0; // Car 클래스의 count 값을 0으로 설정

// Car 클래스의 생성자 선언
Car::Car(int s, int g, string c) : speed(s), gear(g), color(c){
    count++;    // 생성자가 한번 호출되면 count 값을 1 증가시킨다.
}

// Car 클래스의 소멸자 선언
Car::~Car(){
    count--;    // 객체가 소멸되면 count 값을 1 감소시킨다.
}

// Car의 값을 출력해준다.
void Car::print(){
    cout << "속도: " << speed << " 기어: " << gear << " 색상: " << color << endl;
}

// tmp라는 Car 객체를 생성시키고, 생성된 객체를 반환한다.
// 여기서 Visual Studio 상의 컴파일러에서는 생성된 임시 객체를 반환한다.
// gcc 컴파일러에서는 생성된 실제 객체를 반환한다.
Car createCar(){
    Car tmp(0,1,"metal");

    return tmp;
}