#include "실습13_complex.h"

int main(void){
    Complex x(2,3), y(4,6), z;

    cout << "첫번째 복소수 x: ";
    x.print();

    cout << "두번째 복소수 y: ";
    y.print();

    z = x.add(y);

    cout << "z = x + y = ";
    z.print();

    return 0;
}