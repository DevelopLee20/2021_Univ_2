#include "Manager.h"

void Manager::modify(int s, int b){
    salary = s;
    bonus = b;
}

void Manager::display(){    // salary, bonus, getRrn() 함수로 반환된 rrn 값을 출력해준다.
    cout << "봉급: " << salary << " 보너스: " << bonus << " 주민등록번호: " << getRrn() << endl;
}