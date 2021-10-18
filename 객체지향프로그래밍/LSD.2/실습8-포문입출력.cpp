#include <iostream>
using namespace std;

int main(void){
    long fact = 1;
    int n;

    cout << "정수를 입력하시오: ";
    cin >> n;

    // 팩토리얼 연산용 반복문
    for(int i=0; i<=n; i++){
        fact = fact * i;
    }

    cout << n << "!은 " << fact << "입니다.\n";

    return 0;
}