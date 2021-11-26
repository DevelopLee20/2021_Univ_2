#include <iostream>
using namespace std;

class Vector{
private:
    double x, y;
public:
    Vector(double xvalue=0.0, double yvalue=0.0) : x(xvalue), y(yvalue){}
    void display(){
        cout << "(" << x << "," << y << ")" << endl;
    }

    Vector &operator=(const Vector &v2){
        this->x = v2.x;
        this->y = v2.y;

        return *this; // 값을 일단 반환해야한다.
    }
};

int main(void){
    Vector v1(1.0,2.0), v2(3.0,4.0);
    v1 = v2;
    v1.display();

    return 0;
}