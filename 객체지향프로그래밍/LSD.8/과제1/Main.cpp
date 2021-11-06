#include <iostream>
#include "Manager.h"

int main(void){
    Manager m;              // Manager 객체 생성

    m.setRrn(2012345);      // rrn 값을 지정해준다
    m.setSalary(2000);      // salary 값을 지정해준다
    m.display();            // 출력
    m.setRrn(1911223);      // rrn 값을 지정해준다
    m.modify(1000,500);     // salary 값과 bonus 값을 지정해준다
    m.display();            // 출력
}