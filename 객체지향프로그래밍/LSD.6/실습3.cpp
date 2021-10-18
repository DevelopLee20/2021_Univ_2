#include <iostream>     // 기본 라이브러리
#include <string>       // 문자열 사용 라이브러리
using namespace std;    // std:: 를 대신 공백으로 사용 가능

class Car{          // Car 클래스 선언
private:            // private으로 해서 외부에선 사용 불가(기본으로 private 되어있음)
    int speed;      // int 변수 선언
    int gear;       // gear 변수 선언
    string color;   // string 변수 선언

public:                                 // public으로 외부에서 사용 가능하도록
    Car(){                              // Car 생성자 선언
        cout << "생성자 호출" << endl;   // cout << 문장 << endl;
        speed = 0;                      // speed 변수 초기화
        gear = 1;                       // gear 변수 초기화
        color = "white";                // color 변수 초기화
    }

    ~Car(){                             // Car 소멸자 ~Car : 소멸자이다.
        cout << "소멸자 호출" << endl;   // cout << 문장 << endl;
    }
};

int main(void){ // 메인 함수
    Car c1;     // Car 클래스의 객체 c1 생성

    return 0;   // 리턴 0함
}