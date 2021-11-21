#include <iostream> // 표준 입출력 라이브러리
#include "Lion.h"   // Lion.h를 참조

int main(void){
    // Lion 객체를 생성하여 Animal 포인터 변수에 저장
    Animal *p = new Lion(); // Animal 생성자, Lion 생성자 호출
    p->eat();   // eat 함수 실행
    p->move();  // move 함수 실행
    p->speak(); // speak 함수 실행
    delete p;   // Animal 소멸자, Lion 소멸자 호출

    return 0;
}