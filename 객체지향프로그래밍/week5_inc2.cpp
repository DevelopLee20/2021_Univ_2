// Car 클래스 만들기
// 타이어를 갈아 낄 수 있도록

#include <iostream>
#include <string>
using namespace std;

class Car{
public: // public, private | default: private
    int speed = 5;
    int gear;
    string color;

    void speedUp(){
        speed += 9;
    }

    void speedDown(){
        speed -= 10;
    }

    void setspeed(int s){
        speed = speed;
    }

    void show(){
        cout << speed << endl;
        cout << gear << endl;
        cout << color << endl;
    }
};

int main(void){
    Car myCar;

    myCar.setspeed(10);

    myCar.show();

    return 0;
}