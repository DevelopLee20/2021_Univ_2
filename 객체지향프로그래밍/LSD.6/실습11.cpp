#include <iostream>
#include "실습11_Date.h"
using namespace std;

Date::Date(){
    year = 2010;
    month = 1;
    day = 1;
}

Date::Date(int year){
    setDate(year,1,1);
}

Date::Date(int year, int month, int day){
    setDate(year, month, day);
}

void Date::setDate(int year, int month, int day){
    this->year = year;
    this->month = month;
    this->day = day;
}

void Date::print(){
    cout << year << "년" << month << "월";
    cout << day << "일" << endl;
}

int main(void){
    Date date1(2009,3,2);
    Date date2(2009);
    Date date3;
    date1.print();
    date2.print();
    date3.print();

    return 0;
}