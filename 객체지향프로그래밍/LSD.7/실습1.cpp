#include <iostream>     // 표준입출력 라이브러리
#include <string>       // 문자열 라이브러리
using namespace std;    // std 사용 안해도 됨

class Car{          // Car 클래스 생성
    int speed;      // Car 의 멤버 변수 speed
    int gear;       // Car 의 멤버 변수 gear
    string color;   // Car 의 멤버 변수 color

public:             // public 으로 클래스 밖에서도 사용 가능
    // 생성자
    Car(int s=0, int g=1, string c="white") : speed(s), gear(g), color(c){
    }

    // 출력 메소드 생성, 반환값은 없다
    void print(){
        cout << "속도: " << speed << " 기어: " << gear << " 색상: " << color << endl;
    }
};

int main(void){
    Car myCar;                          // Car 객체 myCar 생성

    myCar.print();                      // myCar의 print() 메소드 사용

    Car *pCar = new Car(0,1,"blue");    // Car 객체를 동적 생성한 pCar
    pCar->print();                      // pCar의 print() 메소드 사용

    return 0;
}