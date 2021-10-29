#include "실습11_time.h"

Time::Time(){
    time = 0;
    minute = 0;
    second = 0;
}

Time::Time(int t, int m, int s){
    time = t;
    minute = m;
    second = s;
}

void Time::print(){
    cout << time << "시" << minute << "분"
    cout << second << "초\n";
}