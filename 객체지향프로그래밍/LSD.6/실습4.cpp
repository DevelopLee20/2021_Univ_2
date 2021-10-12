#include <iostream>
#include <string>
using namespace std;

class Car{
    string &alias;
    int speed;

public:
    Car(string s) : alias(s){
        cout << alias << endl;
    }
};

int main(void){
    Car c1("꿈의 자동차");

    return 0;
}