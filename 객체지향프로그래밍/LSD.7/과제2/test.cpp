#include <iostream>
using namespace std;

int main(void){
    double a = 3.3123;
    double b = 1.141;
    double c = a/b;
    int d = (int)c;
    
    cout << c << endl;
    cout << d << endl;
    cout << c - d << endl;

    return 0;
}