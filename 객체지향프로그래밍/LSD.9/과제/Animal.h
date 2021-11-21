#include <iostream>             // 표준 입출력 라이브러리

class Animal{                   // Animal 클래스 선언
public:                         // public 상태
    Animal();                   // 생성자
    virtual ~Animal() = 0;      // 소멸자, 추상클래스
    virtual void eat() = 0;     // 추상클래스
    virtual void move() = 0;    // 추상클래스
    virtual void speak() = 0;   // 추상클래스
};