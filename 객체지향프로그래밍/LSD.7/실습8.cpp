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

    static int getCount(){
        return count;
    }
};

int Car::count = 0;

int main(void){
    Car c1(100,0,"blue");
    Car c2(0,0,"white");

    int n = Car::getCount();

    cout << "지금까지 생성된 자동차 수= " << n << endl;

    return 0;
}