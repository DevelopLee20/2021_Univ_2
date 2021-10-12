#pragma  once

#include <iostream>
using namespace std;

class Date{
private:
    int year;
    int month;
    int day;

public:
    Date();
    Date(int year);
    Date(int year, int month, int day);
    void setDate(int year, int month, int day);
    void print();
};