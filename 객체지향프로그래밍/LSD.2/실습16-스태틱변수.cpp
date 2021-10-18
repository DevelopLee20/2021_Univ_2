#include <iostream>
using namespace std;

void sub(void){
    int i = 0;
    static int s = 0;   // 스태틱 변수 선언

    i++;
    s++;
    cout << "i: " << i << "s: " << s << endl;
}

int main(void){
    sub(); // 3번 호출해도 i는 초기화 s는 초기화 되지 않음
    sub();
    sub();

    return 0;
}