#include <iostream>
using namespace std;

void increment(int score[], int n){
    for(int i=0; i<n; i++){
        ++score[i]; // score 배열의 값을 1씩 증가
    }
}

// 평균을 구하는 함수
int get_average(const int score[], int n){
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += score[i];
    }

    return sum / n;
}

int main(void){
    const int STUDENTS = 5;             // 상수 선언
    int grade[STUDENTS] = {1,2,3,4,5};  // 성적 배열 선언
    int avg;

    increment(grade, STUDENTS);         // 성적을 1씩 증가 시킴
    avg = get_average(grade, STUDENTS);
    cout << "평균은 " << avg << "입니다.\n";

    return 0;
}
