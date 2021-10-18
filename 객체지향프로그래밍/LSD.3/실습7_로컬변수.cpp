#include <iostream>
using namespace std;

void swap(int x, int y){    // x, y를 바꿔준다
    int tmp;

    tmp = x;
    x = y;
    y = tmp;
}

// 포인터를 보낸게 아니니까 값이 안바뀌지~
int main(void){
    int a = 100, b = 200;
    cout << "swap() 호출전: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "swap() 호출후: a = " << a << ", b = " << b << endl;
    
    return 0;
}