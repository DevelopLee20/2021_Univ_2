#include "Mammal.h" // Mammal.h 헤더파일 참조

class Lion : public Mammal{ // Mammal 클래스를 상속받은 Lion 클래스 생성
public:
    Lion();         // 생성자
    ~Lion();        // 소멸자
    void eat();     // eat 함수
    void move();    // move 함수
    void speak();   // speak 함수
};