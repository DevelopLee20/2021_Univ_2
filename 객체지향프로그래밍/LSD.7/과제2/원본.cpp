#include <iostream>
#include <string>
using namespace std;

class Calculator{
    char operand[6] = {'+','-','*','/','%','^'};
    double value1, value2;
    string window;
    double result;
    double memory;
    int operand_position;

public:
    Calculator(){
        result = 0;
        memory = 0;
        window = "";
    }

    double GetResult(){
        return result;
    }

    double GetMemory(){
        return memory;
    }

    void print(){
        cout << "=======================" << endl;
        cout << this->window << " = " << GetResult() << endl;
        cout << ">> ";
        cin >> this->window;
    }

    void GetOperandPosition(){
        int oper_pos = -1;
        for(int i=0; i<this->window.length(); i++){
            for(int j=0; j<6; j++){
                if (this->window[i] == this->operand[j]){
                    oper_pos = i;
                    break;
                }
            }
            if (oper_pos != -1) break;
        }
        operand_position = oper_pos;
    }

    void OrderFunctionCall(){
        GetOperandPosition();
        if (operand_position == 0){
            value1 = stod(window.substr(1,window.length()));

            switch (window[operand_position])
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
            window = to_string(memory) + window;
        }
        else{
            value1 = stod(window.substr(0,operand_position));
            value2 = stod(window.substr(operand_position+1,window.length()));

            switch (window[operand_position])
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

    double Add(double value1){
        memory = result;
        result = result + value1;

        return result;
    }

    double Add(double value1, double value2){
        memory = result;
        result = value1 + value2;

        return result;
    }

    double Sub(double value1){
        memory = result;
        result = result - value1;

        return result;
    }

    double Sub(double value1, double value2){
        memory = result;
        result = value1 - value2;

        return result;
    }

    double Div(double value1){
        memory = result;
        result = result / value1;

        return result;
    }

    double Div(double value1, double value2){
        memory = result;
        result = value1 / value2;

        return result;
    }

    double Mul(double value1){
        memory = result;
        result = result * value1;

        return result;
    }

    double Mul(double value1, double value2){
        memory = result;
        result = value1 * value2;

        return result;
    }

    double Rest(double value1){
        memory = result;
        while(result >= value1){
            result  = result - value1;
        }

        return result;
    }

    double Rest(double value1, double value2){
        memory = result;
        result = value1;
        while(result >= value2){
            result  = result - value2;
        }

        return result;
    }

    double Square(double value1){
        memory = result;
        for(int i=0; i<value1-1; i++){
            result = result * memory;
        }

        return result;
    }

    double Square(double value1, double value2){
        memory = result;
        result = value1;
        for(int i=0; i<value2-1; i++){
            result = result * value1;
        }

        return result;
    }
};

int main(void){
    Calculator cal;

    while(1){
        cal.print();
        cal.OrderFunctionCall();
    }

    return 0;
}