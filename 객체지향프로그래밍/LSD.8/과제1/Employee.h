#include <iostream>
#include <string>
using namespace std;

class Employee{
    int rrn;
protected:
    int salary;
public:
    string name;
    void setSalary(int salary);
    void setRrn(int rrn);       // rrn 변수가 private 형식이므로 외부에서 매개변수로 값을 변경하기 위해 set 메소드를 추가하였다.
    int getSalary();
    int getRrn();               // rrn 변수가 private 형식이므로 외부에서 값을 반환 받기 위해 get 메소드를 추가하였다.
};