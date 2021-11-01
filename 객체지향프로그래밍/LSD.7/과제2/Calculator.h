#include <iostream>                                 // 표준 입출력 라이브러리
#include <string>                                   // 문자열을 위한 라이브러리
using namespace std;                                // std:: 를 사용하지 않아도 함수를 사용가능하다.

class Calculator{                                   // Calculator 클래스 선언
private:                                            // 외부에서 접근 불가능하다
    char operand[6] = {'+','-','*','/','%','^'};    // 사용가능한 연산자의 배열이다.
    double value1, value2;                          // 매개변수1과 매개변수2 역할을 하는 변수
    string window;                                  // 계산기에 입력되는 값 전체를 저장할 변수
    double memory;                                  // 메모리필드 역할
    double save;                                    // 메모리 값을 변경할때 임시 저장할 변수
    int operand_position;                           // 연산자의 위치를 저장할 변수

public:                                             // 외부에서 접근 가능
    Calculator();                                   // Calculator 클래스 생성자 선언
    double GetMemory();                             // Memory 변수를 반환하는 메소드
    void print();                                   // 계산기의 인터페이스 역할
    void GetOperandPosition();                      // 연산자의 위치를 찾는 메소드
    void OrderFunctionCall();                       // 연산자에 위치와 값에 따라서 다른 함수를 호출하는 메소드
    double Add(double value1);                      // 더하기 메소드, 매개변수 1개 버전
    double Add(double value1, double value2);       // 더하기 메소드, 매개변수 2개 버전
    double Sub(double value1);                      // 빼기 메소드, 매개변수 1개 버전
    double Sub(double value1, double value2);       // 빼기 메소드, 매개변수 2개 버전
    double Div(double value1);                      // 나누기 메소드, 매개변수 1개 버전
    double Div(double value1, double value2);       // 나누기 메소드, 매개변수 2개 버전
    double Mul(double value1);                      // 곱하기 메소드, 매개변수 1개 버전
    double Mul(double value1, double value2);       // 곱하기 메소드, 매개변수 2개 버전
    double Rest(double value1);                     // 나머지 메소드, 매개변수 1개 버전
    double Rest(double value1, double value2);      // 나머지 메소드, 매개변수 2개 버전
    double Square(double value1);                   // 제곱 메소드, 매개변수 1개 버전
    double Square(double value1, double value2);    // 제곱 메소드, 매개변수 2개 버전
};