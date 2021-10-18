#include <iostream>     // 표준 입출력
#include <string>       // string 자료형 사용
using namespace std;    // std를 사용하지 않아도됨

int main(void){
    string s1("Slow"), s2("steady");    // string 선언 이렇게도 됩니다.
    string s3 = "the race.";            // string 선언
    string s4;                          // string 선언

    s4 = s1 + "and " + s2 + "wins " + s3;
    cout << s4 << endl;

    return 0;
}