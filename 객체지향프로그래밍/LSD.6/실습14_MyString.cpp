#include <iostream>          // 표준입출력 라이브러리
#include <cstring>           // 이거 예제에는 안쓰여있는데 쓰면 인식함
#include "실습14_MyString.h" // 헤더파일 임포트
using namespace std;         // std를 쓰지 않아도 됨

MyString::MyString(const char *s){ // 추상적인 정보들의 내용을 담아줌 Class명::메소드명
    if(s == NULL){          // s포인터가 NULL이면 (내용이 없으면)
        pBuf = new char[1]; // pBuf 변수에 char[] 1의 크기를 가진 객체를 생성한다
        pBuf[0] = NULL;     // pBuf의 0번지는 NULL이 된다. (NULL이 있어야 없다고 인식하니까)
    }
    else{                               // s포인터가 NULL이 아니라면
        pBuf = new char[strlen(s)+1];   // pBuf 변수를 길이 + 1의 크기로 객체를 생성한다. (NULL도 저장해야되서 라고 추측됨)
        strcpy(pBuf, s);                // s에 pBuf를 복사함
    }
}

MyString::MyString(MyString &s){    // MyString 클래스의 MyString 생성자 코드를 작성한다.
    pBuf = new char[s.getSize()+1]; // MyString 객체의 주소를 매개변수로 받아 객체를 생성 후, pBuf에 저장한다.
    strcpy(pBuf, s.pBuf);           // pBuf를 s.pBuf에 복사한다.
}

MyString::~MyString(){  // MyString의 소멸자를 생성한다.
    if(pBuf){           // pBuf가 내용이 있으면
        delete [] pBuf; // pBuf 객체를 삭제한다.
    }
}

void MyString::print(){     // print() 출력 메소드
    cout << pBuf << endl;   // 문장을 출력한다.
}

int MyString::getSize(){    // getSize 메소드로
    return strlen(pBuf);    // pBuf의 문장의 길이를 반환한다. 반환형은 int
}