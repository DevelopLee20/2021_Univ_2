#include "Calculator.h"             // 계산기 헤더파일 include

int main(void){
    Calculator cal;                 // 계산기 객체 생성
 
    while(1){                       // 무한 반복해서 계속 계산기를 이용함
        cal.print();                // 계산기의 메모리 필드와 입력을 위한 창을 출력함
        cal.OrderFunctionCall();    // 입력받은 값과 연산자에 따라서 다른 함수를 호출해준다.
    }

    return 0;
}