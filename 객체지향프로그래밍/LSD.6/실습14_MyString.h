#include <iostream>     // 표준입출력 라이브러리
using namespace std;    // std를 안써도 된다.

// 추상적인 정보만 담겨져 있음 헤더파일에는
class MyString{ // MyString 클래스 생성
private:        // private 으로 설정
    char *pBuf; // 문자형 포인터 생성

public:                             // 외부에서도 사용가능함
    MyString(const char *s = NULL); // 캐릭터 포인터를 초기화 const는 상수
    MyString(MyString &s);          // 문자열 포인터의 주소를 매개변수로
    ~MyString();                    // 객체 소멸

    void print();                   // 출력
    int getSize();                  // getSize
};