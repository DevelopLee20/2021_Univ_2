#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

class Manager : public Employee{
    int bonus;
public:
    Manager(int b=0) : bonus(b){}
    void modify(int s, int b);      // salary 값은 상속받은 Employee 클래스의 멤버변수에서 가져온다. protected 형은 같은 패키지에서 접근 가능하다.
    void display();
};