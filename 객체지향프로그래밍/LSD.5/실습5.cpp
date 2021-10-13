#include <iostream>
#include <string>
using namespace std;

class Employee{
    string name;
    int salary;
    int age;
    
    int getSalary(){
        return salary;
    }

public:
    int getAge(){
        return age;
    }

    string getName(){
        return name;
    }
};

int main(void){
    Employee e;
    // 주석처리는 default 설정이 private이므로 public으로 변경해주어야 작동 잘함.
    // e.salary = 300;
    // e.age = 26;

    // int sa = e.getSalary();

    string s = e.getName();
    int a = e.getAge();

    return 0;
}