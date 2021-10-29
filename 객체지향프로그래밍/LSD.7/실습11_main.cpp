#include "실습11_time.h"
#include "실습11_alarm.h"

int main(void){
    Time alarm(6,0,0);
    Time current(12,56,34);
    AlarmClock c(alarm, current);

    c.print();
    
    return 0;
}