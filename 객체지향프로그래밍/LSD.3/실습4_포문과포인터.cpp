#include <iostream>
using namespace std;

int main(void){
    const int STUDENTS = 5; // 상수 선언
    int grade[STUDENTS] = {10,20,30,40,50};

    // 포인터의 위치를 기준으로 for 문으로 하나씩 포인터 값을 올린다.
    for(int *p = grade, *pend = grade + STUDENTS; p != pend; p++){
        cout << *p << " ";
    }
    
    return 0;
}