#include <iostream>
#include <string>
using namespace std;

class Car{
private:
    int speed;
    int gear;
    string color;

public:
    Car(){
        cout << "생성자 호출" << endl;
        speed = 0;
        gear = 1;
        color = "white";
    }

    ~Car(){
        cout << "소멸자 호출" << endl;
    }
};

int main(void){
    Car c1;

    return 0;
}