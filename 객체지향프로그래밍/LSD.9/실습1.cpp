#include <iostream>
using namespace std;

class Shape{
protected:
    int x,y;
public:
    void draw(){
        cout << "Shape Draw" << endl;
    }

    void setOrigin(int x, int y){
        this->x = x;
        this->y = y;
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
        cout << "Circle draw" << endl;
    }
};

int main(void){
    Shape *ps = new Rectangle();

    ps->setOrigin(10,10);
    ps->draw();

    ((Rectangle*)ps)->setWidth(100);
    delete ps;
}