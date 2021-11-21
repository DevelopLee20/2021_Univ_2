#include <iostream>
#include <string>
using namespace std;

class Shape{
protected:
    int x, y;
public:
    void setOrigin(int x, int y){
        this->x = x;
        this->y = y;
    }
    virtual void draw(){    // void draw로 작성시 우선 호출됨
        cout << "Shape Draw" << endl;
    }
};

class Rectangle : public Shape{
private:
    int width, height;
public:
    void setWidth(int w){
        width = w;
    }
    void setHeight(int h){
        height = h;
    }
    void draw(){
        cout << "Rectangle Draw" << endl;
    }
};

class Circle : public Shape{
private:
    int radius;
public:
    void setRadius(int r){
        radius = r;
    }
    void draw(){
        cout << "Circle Draw" << endl;
    }
};

int main(void){
    Shape *ps = new Rectangle();
    ps->draw(); // Rectangle Draw
    delete ps;

    Shape *ps1 = new Circle();
    ps1->draw(); // Circle Draw
    delete ps1;

    return 0;
}