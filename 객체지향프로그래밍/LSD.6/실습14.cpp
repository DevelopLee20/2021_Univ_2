#include <iostream>          // 표준입출력 라이브러리
#include "실습14_MyString.h" // MyString.h 헤더파일의 클래스를 사용한다.
using namespace std;         // std를 쓰지 않아도 된다.

int main(void){                 // 메인 함수
    MyString str1;              // MyString 객체 생성
    MyString str2("Hello");     // MyString 객체 생성
    MyString str3 = "World!";   // MyString 객체 생성
    MyString str4(str3);        // MyString 객체 생성

    str1.print();   // 객체 물량 출력
    str2.print();   // 객체 물량 출력
    str3.print();   // 객체 물량 출력
    str4.print();   // 객체 물량 출력

    return 0;       // 리턴
}