#include <iostream>
#include <string>
using namespace std;

class Car{
    int speed;
    int gear;
    string color;
    
public:
    Car(int s=0, int g=1, string c="white") : speed(s), gear(g), color(c){
    }

    int getSpeed(){
        return speed;
    }

    void setSpeed(int speed){
        if(speed > 0){
            this->speed = speed;
        }
        else{
            this->speed = 0;
        }
    }

    void isFaster(Car *p){
        if(this->getSpeed() > p->getSpeed()){
            this->print();  // print(); 랑 같이 작동함, 멤버 함수임을 강조하는 것 뿐임
        }
        else{
            p->print();
        }

        cout << "의 자동차가 더 빠름" << endl;
    }

    void print(){
        cout << "속도: " << speed;
        cout << "기어: " << gear << "색상: " << color;
    }
};

int main(void){
    Car c1(0,1,"blue");     // 객체 정적 생성
    Car c2(100,3,"red");    // 객체 정적 생성
    c1.isFaster(&c2);

    return 0;
}