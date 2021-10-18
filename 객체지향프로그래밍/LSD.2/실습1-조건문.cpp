#include <iostream> // 표준입출력 라이브러리
using namespace std;// std를 사용하지 않아도 됨

int main(void){ // 메인함수
    int x, y;   // x, y int 변수 선언

    cout << "x값을 입력하시오: ";    // cout 으로 문장을 출력 endl이 없어서 enter가 작동 안함
    cin >> x;                       // cin 으로 x에 변수를 입력받음

    cout << "y값을 입력하시오: ";    // cout으로 문장을 출력, endl 이 없어서 엔터를 수행하지 않음
    cin >> y;                       // cin으로 y 변수에 값을 입력받음

    if (x > y){                             // if 문으로 비교
        cout << "x가 y보다 큽니다." << endl; // 문장 출력
    }
    else{
        cout << "y가 x보다 큽니다." << endl; // 문장 출력
    }

    return 0;
}