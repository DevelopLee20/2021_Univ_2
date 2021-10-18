#include <iostream>
using namespace std;

int main(void){
    char *pc;   // 문자형 포인터 선언
    int *pi;    // int형 포인터 선언
    double *pd; // double형 포인터 선언

    // 포인터 주소의 위치를 10000으로 지정
    pc = (char *)10000;     // 포인터 주소에 값 10000을 넣는다. 포인터주소로 캐스팅
    pi = (int *)10000;      // int 포인터로 캐스팅 10000을 넣으면서
    pd = (double *)10000;   // double 포인터로 캐스팅 데이터형에 따라서 주소값이 달라진다.
    cout << "증가 전 pc = " << (void *)pc << " pi = " << pi << " pd = " << pd << endl;

    pc++;   // 다음 포인터는 데이터형에 따라서 증가함
    pi++;
    pd++;

    cout << "증가 후 pc = " << (void *)pc << " pi = " << pi << " pd = " << pd << endl;

    return 0;
}