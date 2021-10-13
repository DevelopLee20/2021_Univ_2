#include <iostream>
using namespace std;

class Time{
private:
    int hour;
    int minute;
    int second;

public:
    Time();
    Time(int h, int m, int s);
    void setTime(int h, int m, int s);
    void print();
};