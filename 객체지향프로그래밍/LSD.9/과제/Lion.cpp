#include "Lion.h"   // Lion.h 헤더파일 참조
using namespace std;// std를 쓰지 않아도 cout, endl 사용가능

Lion::Lion(){   // 생성자 내부 코드 작성
    cout << "Lion 생성자" << endl;
}

Lion::~Lion(){  // 소멸자 내부 코드 작성
    cout << "Lion 소멸자" << endl;
}

void Lion::eat(){   // eat 함수 내부 코드 작성
    cout << "Lion의 eat()" << endl;
}

void Lion::move(){  // move 함수 내부 코드 작성
    cout << "Lion의 move()" << endl;
}

void Lion::speak(){ // speak 함수 내부 코드 작성
    cout << "Lion의 speak()" << endl;
}