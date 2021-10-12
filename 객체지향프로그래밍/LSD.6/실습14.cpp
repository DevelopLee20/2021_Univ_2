#include <iostream>
#include "실습14_MyString.h"
using namespace std;

int main(void){
    MyString str1;
    MyString str2("Hello");
    MyString str3 = "World!";
    MyString str4(str3);

    str1.print();
    str2.print();
    str3.print();
    str4.print();

    return 0;
}