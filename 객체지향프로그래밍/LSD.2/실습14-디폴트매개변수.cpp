#include <iostream>
using namespace std;

// 함수의 매개변수에 기본적인 매개변수의 디폴트 매개변수가 있다. 매개변수를 입력하지 않으면 디폴트가 자동으로 입력됨
int calc_deposit(int salary=300, int month=12){
    return salary * month;
}

int main(void){
    cout << "0개의 디폴트 매개 변수 사용" << endl;
    cout << calc_deposit(200, 6) << endl;

    cout << "1개의 디폴트 매개 변수 사용" << endl;
    cout << calc_deposit(200) << endl;

    cout << "2개의 디폴트 매개 변수 사용" << endl;
    cout << calc_deposit() << endl;

    return 0;
}