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
    void setRrn(int rrn);
    int getSalary();
    int getRrn();
};

void Employee::setSalary(int salary){
    this->salary = salary;
}

void Employee::setRrn(int rrn){
    this->rrn = rrn;
}

int Employee::getSalary(){
    return salary;
}

int Employee::getRrn(){
    return rrn;
}

class Manager : public Employee{
    int bonus;
public:
    Manager(int b=0) : bonus(b){}
    void modify(int s, int b);
    void display();
};

void Manager::modify(int s, int b){
    salary = s;
    bonus = b;
}

void Manager::display(){
    cout << "봉급: " << salary << " 보너스: " << bonus << " 주민등록번호: " << getRrn() << endl;
}

int main(void){
    Manager m;
    m.setRrn(2012345);
    m.setSalary(2000);
    m.display();
    m.setRrn(1911223);
    m.modify(1000,500);
    m.display();
}