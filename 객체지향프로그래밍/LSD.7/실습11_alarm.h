#include <iostream>
#include <string>
using namespace std;

class AlarmClock{
private:
    Time currentTime;
    Time alarmTime;

public:
    AlarmClock(Time a, Time c);
    void print();
};