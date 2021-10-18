#include <iostream>
using namespace std;

int main(void){
    int sum = 0;

    // 1부터 10까지 합쳐서 계산함 for 문은 조건에 충족하지 못하면 break
    for(int i=1; i<=10; i++){
        sum += i;
    }

    cout << "1부터 10까지의 정수의 합 = " << sum << endl;
    return 0;
}