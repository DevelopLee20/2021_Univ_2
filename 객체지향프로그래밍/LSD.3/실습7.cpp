#include <iostream>
using namespace std;

void swap(int x, int y){
    int tmp;

    tmp = x;
    x = y;
    y = tmp;
}

int main(void){
    int a = 100, b = 200;
    cout << "swap() 호출전: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "swap() 호출후: a = " << a << ", b = " << b << endl;
    
    return 0;
}