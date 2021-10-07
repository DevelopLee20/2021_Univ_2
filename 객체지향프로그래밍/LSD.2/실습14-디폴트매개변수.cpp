#include <iostream>
using namespace std;

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