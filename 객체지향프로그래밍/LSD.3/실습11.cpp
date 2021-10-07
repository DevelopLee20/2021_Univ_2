#include <iostream>
using namespace std;

int main(void){
    char str[30] = "C++ language is easy";
    int i=0;

    while( str[i] != 0 ){
        i++;
    }
    cout << "문자열 " << str << "의 길이는 " << i << "입니다." << endl;

    return 0;
}