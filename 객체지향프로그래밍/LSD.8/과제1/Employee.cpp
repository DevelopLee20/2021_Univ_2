#include "Employee.h"

void Employee::setSalary(int salary){
    this->salary = salary;
}

void Employee::setRrn(int rrn){
    this->rrn = rrn;    // rrn 값을 지정해준다.
}

int Employee::getSalary(){
    return salary;
}

int Employee::getRrn(){
    return rrn;         // rrn 값을 반환해준다.
}