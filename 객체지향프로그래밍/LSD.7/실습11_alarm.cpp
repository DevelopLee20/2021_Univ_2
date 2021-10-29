#include "실습11_alarm.h"

AlarmClock::AlarmClock(Time a, Time c){
    alarmTime = a;
    currentTime = c;
}

void AlarmClock::print(){
    cout << "현재시각: ";
    currentTime.print();
    cout << "알람시각: ";
    alarmTime.print();
}