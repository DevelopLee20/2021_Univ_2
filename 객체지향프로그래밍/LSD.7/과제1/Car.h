#include <iostream>     // 표준입출력 라이브러리
#include <string>       // string 형 사용을 위한 라이브러리
using namespace std;    // std::를 쓰지 않아도 cin, cout을 사용 가능함

class Car{          // Car 클래스 선언
    int speed;      // 멤버 변수 speed 선언
    int gear;       // 멤버 변수 gear 선언
    string color;   // 멤버 변수 color 선언

// 위의 내용은 private으로 외부에서 직접 호출 불가능하지만
// 이 아래부터는 public으로 직접 호출이 가능하다.
public:
    static int count;                           // 정적 변수 count 선언

    Car(int s=0, int g=1, string c="white");    // 디폴트 매개변수가 있는 Car 클래스의 생성자 선언
    ~Car();                                     // Car 클래스의 소멸자 선언
    int getSpeed();                             // speed를 반환
    void setSpeed(int speed);                   // speed 변수에 매개변수 값을 할당
    void print();                               // 지금까지 생성된 자동차 수 출력
};

Car createCar();                                // Car을 반환형으로 가지는 createCar 함수 선언