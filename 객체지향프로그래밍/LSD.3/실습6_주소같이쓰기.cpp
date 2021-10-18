#include <iostream>
using namespace std;

int main(void){
    int var;        // int 형 변수 선언
    int &ref = var; // ref의 주소는 var꺼를 쓴다

    var = 10;
    cout << "var의 값: " << var << endl;    // 얘는 10이지
    cout << "ref의 값: " << ref << endl;    // 얘는 왜 10 따라옴 ㅋㅋ

    ref = 20;   // ref가 20이면
    cout << "var의 값: " << var << endl;    // var의 주소를 ref가 공유함.
    cout << "ref의 값: " << ref << endl;    // 주소를 같이 씀

    return 0;
}