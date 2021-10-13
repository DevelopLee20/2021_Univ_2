#include <iostream>
using namespace std;

int main(void){
    int var;
    int &ref = var;

    var = 10;
    cout << "var의 값: " << var << endl;
    cout << "ref의 값: " << ref << endl;

    ref = 20;
    cout << "var의 값: " << var << endl;
    cout << "ref의 값: " << ref << endl;

    return 0;
}