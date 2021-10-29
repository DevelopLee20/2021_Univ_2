#include <iostream>
#include <string>
using namespace std;

class Time{
private:
    int time;
    int minute;
    int second;

public:
    Time();
    Time(int t, int m, int s);
    void print();
};