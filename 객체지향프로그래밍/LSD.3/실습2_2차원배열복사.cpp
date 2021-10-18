#include <iostream>
using namespace std;
const int ROWS = 3; // 상수 선언
const int COLS = 3; // 상수 선언

int main(void){
    int A[ROWS][COLS] = {{2,3,0},{8,9,1},{7,0,5}};
    int B[ROWS][COLS] = {{1,0,0},{1,0,0},{1,0,0}};
    int C[ROWS][COLS];  // 복사할 배열 선언

    for(int r=0; r<ROWS; r++){
        for(int c=0; c<COLS; c++){      // 통짜로 복사
            C[r][c] = A[r][c] + B[r][c];
        }
    }

    for(int r=0; r<ROWS; r++){
        for(int c=0; c<COLS; c++){
            cout << C[r][c] << " "; // 하나씩 출력
        }
        cout << endl;   // 엔터 출력
    }
    return 0;
}