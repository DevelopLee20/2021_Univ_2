#include <iostream>
#include "실습12_Time.h"
using namespace std;

Time::Time(){
    setTime(0,0,0);
}

Time::Time(int h, int m, int s){
    setTime(h, m, s);
}

void Time::setTime(int h, int m, int s){
    hour = ((h >= 0 && h < 24) ? h : 0);
    minute = ((m >= 0 && m < 60) ? m : 0);
    second = ((s >= 0 && s < 60) ? s : 0);
}

void Time::print(){
    cout << hour << ":" << minute << ":" << second << endl;
}

int main(void){
    Time time1;

    cout << "기본 생성자 호출 후 시간: ";
    time1.print();

    Time time2(13,27,6);
    cout << "두번째 생성자 호출 후 시간: ";
    time2.print();

    Time time3(99,66,77);
    cout << "올바르지 않은 시간 설정 후 시간: ";
    time3.print();

    return 0;
}