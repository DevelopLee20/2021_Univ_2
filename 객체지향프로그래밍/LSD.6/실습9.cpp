#include <iostream>
#include <string>
using namespace std;

class Car{
    int speed;
    int gear;
    string color;

public:
    Car(int s, int g, string c) : speed(s), gear(g), color(c){
        cout << "일반 생성자 호출" << endl;
    }

    Car(const Car &obj) : speed(obj.speed), gear(obj.gear), color(obj.color){
        cout << "복사 생성자 호출" << endl;
    }

    int getSpeed(){
        return speed;
    }

    int getGear(){
        return gear;
    }

    string getColor(){
        return color;
    }

    void print(){
        cout << "=============" << endl;
        cout << "속도: " << speed << endl;
        cout << "기어: " << gear << endl;
        cout << "색상: " << color << endl;
        cout << "=============" << endl;
    }
};

void isMoving(Car obj){
    if(obj.getSpeed() > 0){
        cout << "움직이고 있습니다" << endl;
    }
    else{
        cout << "정지해 있습니다" << endl;
    }
}

int main(void){
    Car c(0,1,"white");
    isMoving(c);

    return 0;
}