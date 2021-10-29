#include <iostream>
#include <string>
using namespace std;

class Car{
    int speed;
    int gear;
    string color;

public:
    static int count;

    Car(int s=0, int g=1, string c="white"): speed(s), gear(g), color(c){
        count++;
    }

    ~Car(){
        count--;
    }

    void print(){
        cout << "속도: " << speed << "기어: " << gear << "색상: " << color << endl;
    }
};

int Car::count = 0;

int main(){
    cout << "지금까지 생성된 자동차 수= " << Car::count << endl;

    Car c1(100,0,"blue");
    Car c2(0,0,"white");
    cout << "지금까지 생성된 자동차 수= " << Car::count << endl;

    Car c3(0,0,"red");
    cout << "지금까지 생성된 자동차 수= " << c1.count << endl;
    cout << "지금까지 생성된 자동차 수= " << c2.count << endl;

    return 0;
}