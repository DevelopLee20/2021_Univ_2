#include <iostream> // 표준 입출력
using namespace std;// std없이 사용가능함

int main(void){
    const int STUDENTS = 10;    // 상수 STUDENTS 선언 이거는 절대 바뀌지 않음
    int grade[STUDENTS];        // 성적 배열 생성
    int sum = 0;                // 합 저장
    int average;                // 평균 저장

    for(int i=0; i<STUDENTS; i++){              // 학생수 만큼 반복
        cout << "학생들의 성적을 입력하시오: ";
        cin >> grade[i];                        // 배열에 차례로 저장
    }
    for(int i=0; i<STUDENTS; i++){  // 학생수 만큼 반복
        sum += grade[i];            // 배열의 값을 합함
    }
    average = sum / STUDENTS;       // 평균을 구함
    cout << "성적 평균=" << average << endl;

    return 0;
}