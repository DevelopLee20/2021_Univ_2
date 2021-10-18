#include <iostream>
using namespace std;

int main(void){
    int answer = 59;    // 정답
    int guess;
    int tries = 0;

    do{ // do while 문은 문장 최소 1회 실행 후 조건문을 참조? 한다.
        cout << "정답을 추측하여 보시오: ";
        cin >> guess;
        tries++;

        if (guess > answer){
            cout << "제시한 정수가 높습니다.\n";
        }
        if (guess < answer){
            cout << "제시한 정수가 낮습니다.\n";
        }
    } while(guess != answer);   // 조건문 비교

    cout << "축하합니다. 시도횟수=" << tries << endl;

    return 0;
}