#include <iostream>
using namespace std;

// 함수 선언 후 사용 n 정수를 받아서 사용한다
int square(int n){
    return (n*n);
}

int main(void){
    int n;
    cout << "제곱할 정수를 입력하시오: ";
    cin >> n;
    cout << square(n) << endl;
    
    return 0;
}