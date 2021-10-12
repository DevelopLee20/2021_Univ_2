#include <iostream>
#include "실습14_MyString.h"
#include <string.h>
using namespace std;

MyString::MyString(const char *s){
    if(s == NULL){
        pBuf = new char[1];
        pBuf[0] = NULL;
    }
    else{
        pBuf = new char[::strlen(s)+1];
        strcpy(pBuf, s);
    }
}

MyString::MyString(MyString &s){
    pBuf = new char[s.getSize()+1];
    strcpy(pBuf, s.pBuf);
}

MyString::~MyString(){
    if(pBuf){
        delete [] pBuf;
    }
}

void MyString::print(){
    cout << pBuf << endl;
}

int MyString::getSize(){
    return strlen(pBuf);
}