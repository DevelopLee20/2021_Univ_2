#include <iostream>
using namespace std;

int main(void){
    char letter;    // char 형 데이터

    while(1){
        cout << "소문자를 입력하시오: ";
        cin >> letter;

        // 종료를 위한 조건문 while(1)을 깨기 위한 조건문
        if (letter == 'Q'){
            break;
        }
        // 이렇게 비교되는 이유는 아스키코드를 비교하기 때문에 정수로 치환해서 값의 사이에 있음만 알면 된다.
        if (letter < 'a' || letter > 'z'){  
            continue;
        }

        letter -= 32;
        cout << "변환된 대문자는 " << letter << "입니다.\n";
    }

    return 0;
}