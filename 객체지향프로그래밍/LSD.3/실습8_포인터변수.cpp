#include <iostream>
using namespace std;

void swap(int *px, int *py){
    int tmp;
    tmp = *px; *px = *py; *py = tmp;
}

// 포인터를 사용해서 바꿨으니 바뀌지
int main(void){
    int a = 100, b = 200;
    cout << "swap() 호출 전: a = " << a << ", b = " << b << endl;
    swap(&a, &b);
    cout << "swap() 호출 후: a = " << a << ", b = " << b << endl;

    return 0;
}