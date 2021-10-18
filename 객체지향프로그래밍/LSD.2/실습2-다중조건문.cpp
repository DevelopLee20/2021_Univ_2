#include <iostream> // 표준 입출력 라이브러리
using namespace std;// std를 쓰지 않아도 됨

int main(void){                     // 메인 함수
    int age;                        // int 형 변수 선언
    cout << "나이를 입력하시오: ";   // cout으로 문장 출력
    cin >> age;                     // cin으로 변수를 입력받음

    // if else if else 사용
    if (age <= 12){
        cout << "어린이입니다." << endl;
    }
    else if (age <= 19){
        cout << "청소년입니다." << endl;
    }
    else{
        cout << "성인입니다." << endl;
    }

    return 0;
}