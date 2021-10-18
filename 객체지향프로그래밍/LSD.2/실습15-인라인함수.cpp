#include <iostream>
using namespace std;

// inline 함수인데 그냥 그대로 대입해버림 함수를
inline double square(double i){
    return i*i;
}

int main(void){
    cout << "2.0의 제곱은 " << square(2.0) << endl;
    cout << "3.0의 제곱은 " << square(3.0) << endl;

    return 0;
}