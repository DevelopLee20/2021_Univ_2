#include <iostream>
using namespace std;

int main(void){
    const int STUDENTS = 5;
    int grade[STUDENTS] = {10,20,30,40,50};

    for(int *p = grade, *pend = grade + STUDENTS; p != pend; p++){
        cout << *p << " ";
    }
    
    return 0;
}