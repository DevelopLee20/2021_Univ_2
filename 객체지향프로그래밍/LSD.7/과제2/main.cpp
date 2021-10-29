#include <iostream>
using namespace std;

class Calculator{
    double result;
    double memory;

public:
    Calculator(){
        result = 0;
        memory = 0;
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

    cout << "==========================" << endl;
    cout << "cal.Add(100)   : " << cal.Add(100) << endl;
    cout << "cal.Sub(5)     : " << cal.Sub(5) << endl;
    cout << "cal.Div(5)     : " << cal.Div(5) << endl;
    cout << "cal.Mul(10)    : " << cal.Mul(10) << endl;
    cout << "cal.Rest(6)    : " << cal.Rest(6) << endl;
    cout << "cal.Square(3)  : " << cal.Square(3) << endl;
    cout << "==========================" << endl;
    cout << "cal.Add(10,10)     : " << cal.Add(10,10) << endl;
    cout << "cal.Sub(20,10)     : " << cal.Sub(20,10) << endl;
    cout << "cal.Div(100,2)     : " << cal.Div(100,2) << endl;
    cout << "cal.Mul(4,10)      : " << cal.Mul(4,10) << endl;
    cout << "cal.Rest(100,3)    : " << cal.Rest(100,3) << endl;
    cout << "cal.Square(2,10)   : " << cal.Square(2,10) << endl;
    cout << "==========================" << endl;

    return 0;
}