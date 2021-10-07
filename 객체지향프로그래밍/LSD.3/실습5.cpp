#include <iostream>
using namespace std;

void increment(int score[], int n){
    for(int i=0; i<n; i++){
        ++score[i];
    }
}

int get_average(const int score[], int n){
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += score[i];
    }

    return sum / n;
}

int main(void){
    const int STUDENTS = 5;
    int grade[STUDENTS] = {1,2,3,4,5};
    int avg;

    increment(grade, STUDENTS);
    avg = get_average(grade, STUDENTS);
    cout << "평균은 " << avg << "입니다.\n";

    return 0;
}
