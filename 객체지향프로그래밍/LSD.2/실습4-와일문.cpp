#include <iostream>
using namespace std;

int main(void){
    int n;
    int i = 1;

    cout << "구구단 중에서 출력하고 싶은 단을 입력하시오: ";
    cin >> n;

    // for 문으로 사용해도 문제 없음
    while(i <= 9){  // 1~9 까지 총 9문장을 출력함
        cout << n << "*" << i << "=" << n * i << endl;
        i++;
    }
    
    return 0;
}