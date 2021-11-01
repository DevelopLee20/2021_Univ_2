#include "Calculator.h"     // Calculator.h include

Calculator::Calculator(){   // Calculator 클래스의 생성자 생성
    memory = 0;             // 메모리 필드를 0으로 초기화
    save = 0;               // save 필드를 0으로 초기화
    window = "";            // 화면의 내용을 공백으로 초기화
}

double Calculator::GetMemory(){ // Calculator 클래스의 GetMemory() 메소드 생성
    return memory;              // memory 값을 반환한다.
}

void Calculator::print(){                                   // Calculator 클래스의 print() 메소드 생성
    cout << "=======================" << endl;              // 구분을 위한 경계선 출력
    cout << this->window << " = " << GetMemory() << endl;   // 계산 수식 출력
    cout << ">> ";                                          // 입력을 안내하는 표시 출력
    cin >> this->window;                                    // 계산식 입력
}

void Calculator::GetOperandPosition(){                  // Calculator 클래스의 GetOperandPosition() 메소드 생성
    int oper_pos = -1;                                  // -1로 초기화
    for(int i=0; i<this->window.length(); i++){         // 입력받은 계산식 문자열에서 연산자가 있는지 찾고, 인덱스 반환
        for(int j=0; j<6; j++){
            if (this->window[i] == this->operand[j]){
                oper_pos = i;                           // 연산자 발견시 인덱스 저장
                break;                        
            }
        }
        if (oper_pos != -1) break;                      // 연산자가 발견되었으면 반복 완전히 종료
    }
    operand_position = oper_pos;                        // 멤버변수 operand_position 변수에 저장
}

void Calculator::OrderFunctionCall(){                       // Calculator 클래스의 OrderFunctionCall 메소드 생성
    GetOperandPosition();                                   // GetOperandposition() 메소드 호출
    if (operand_position == 0){                             // 연산자의 위치가 0번째라면 매개변수 1개인 연산 메소드를 호출
        value1 = stod(window.substr(1,window.length()));    // value1 값에 string to double 로 캐스팅해서 연산자를 제외한 값을 저장한다

        switch (window[operand_position])   // 연산자에 따라서 다른 메소드를 호출한다.
        {
        case '+':
            Add(value1);
            break;
        case '-':
            Sub(value1);
            break;
        case '*':
            Mul(value1);
            break;
        case '/':
            Div(value1);
            break;
        case '%':
            Rest(value1);
            break;
        case '^':
            Square(value1);
            break;
        }
        window = to_string(save) + window;  // 결과값을 window에 저장한다.
    }
    else{
        value1 = stod(window.substr(0,operand_position));                   // string to double 으로 캐스팅 한 값을 연산자를 기준으로 value1과
        value2 = stod(window.substr(operand_position+1,window.length()));   // value2로 나눈다. 예시) 3+2 라면 value1=3, 연산자='+', value2=2

        switch (window[operand_position])   // 연산자에 따라서 다른 메소드를 호출한다.
        {
        case '+':
            Add(value1,value2);
            break;
        case '-':
            Sub(value1,value2);
            break;
        case '*':
            Mul(value1,value2);
            break;
        case '/':
            Div(value1,value2);
            break;
        case '%':
            Rest(value1,value2);
            break;
        case '^':
            Square(value1,value2);
            break;
        }
    }
}

double Calculator::Add(double value1){  // 더하기 메소드 매개변수 1개 버전
    save = memory;                      // 원래 결과를 save에 저장
    memory = memory + value1;           // 이전의 값과 현재의 값을 더한다

    return memory;                      // 더한 결과 값을 반환
}

double Calculator::Add(double value1, double value2){   // 더하기 메소드 매개변수 2개 버전(메소드 오버로딩)
    save = memory;                                      // 원래 결과를 save에 저장
    memory = value1 + value2;                           // 메모리의 값과 현재의 값을 더한다

    return memory;                                      // 더한 결과 값을 반환
}

double Calculator::Sub(double value1){  // 빼기 메소드 매개변수 1개 버전
    save = memory;                      // 원래 결과를 save에 저장               
    memory = memory - value1;           // 메모리 값에서 value1 값을 뺀다

    return memory;                      // 뺀 결과 값을 반환
}

double Calculator::Sub(double value1, double value2){   // 빼기 메소드 매개변수 2개 버전(메소드 오버로딩)
    save = memory;                                      // 원래 결과를 save에 저장
    memory = value1 - value2;                           // 메모리 값과 현재 값을 뺀다

    return memory;                                      // 뺀 결과 값을 반환
}

double Calculator::Div(double value1){  // 나누기 메소드 매개변수 1개 버전
    save = memory;
    memory = memory / value1;

    return memory;
}

double Calculator::Div(double value1, double value2){   // 나누기 메소드 매개변수 2개 버전(메소드 오버로딩)
    save = memory;
    memory = value1 / value2;

    return memory;
}

double Calculator::Mul(double value1){  // 곱하기 메소드 매개변수 1개 버전
    save = memory;
    memory = memory * value1;

    return memory;
}

double Calculator::Mul(double value1, double value2){   // 곱하기 메소드 매개변수 2개 버전(메소드 오버로딩)
    save = memory;
    memory = value1 * value2;

    return memory;
}

double Calculator::Rest(double value1){ // 곱하기 메소드 매개변수 1개 버전
    save = memory;
    while(memory >= value1){
        memory  = memory - value1;
    }

    return memory;
}

double Calculator::Rest(double value1, double value2){  // 곱하기 메소드 매개변수 2개 버전(메소드 오버로딩)
    save = memory;
    memory = value1;
    while(memory >= value2){
        memory  = memory - value2;
    }

    return memory;
}

double Calculator::Square(double value1){   // 제곱 메소드 매개변수 1개 버전
    save = memory;
    for(int i=0; i<value1-1; i++){
        memory = memory * save;
    }

    return memory;
}

double Calculator::Square(double value1, double value2){    // 제곱 메소드 매개변수 2개 버전(메소드 오버로딩)
    save = memory;
    memory = value1;
    for(int i=0; i<value2-1; i++){
        memory = memory * value1;
    }

    return memory;
}