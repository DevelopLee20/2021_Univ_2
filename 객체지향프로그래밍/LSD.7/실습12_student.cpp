#include "실습12_student.h"

Student::Student(const string n, const string t){
    name = n;
    telephone = t;
}

string Student::getTelephone() const{
    return telephone;
}

void Student::setTelephone(const string t){
    telephone = t;
}

string Student::getName() const{
    return name;
}

void Student::setName(const string n){
    name = n;
}