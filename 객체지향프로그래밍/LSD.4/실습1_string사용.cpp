#include <iostream>
#include <string>   // 문자열 사용하기 위한 헤더파일
using namespace std;

int main(void){
    string s1 = "This is a test.";  // 문자열 선언 및 초기화 ""로 초기화
    string s2;                      // 문자열 선언

    cout << s1 << endl;
    cout << "문자열을 입력하시오 ";
    cin >> s2;
    cout << s2 << endl;

    return 0;
}