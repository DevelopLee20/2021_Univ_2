#include <iostream>
using namespace std;

int main(void){
    char str1[7] = "Seoul";                     // 문자형이 문자열도 받을 수 있다.
    char str2[3] = {'i','s'};                   // 뒤에 더해진다 그냥
    char str3[] = "the capital city of Korea."; // 얘도 뒤에 더해진다

    cout << str1 << str2 << str3 << endl;

    return 0;
}