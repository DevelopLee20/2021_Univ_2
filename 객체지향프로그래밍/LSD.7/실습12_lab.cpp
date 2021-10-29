#include "실습12_lab.h"

Lab::Lab(const string n){
    name = n;
    chief = NULL;
    manager = NULL;
}

void Lab::setChief(Student *p){
    chief = p;
}

void Lab::setManager(Student *p){
    manager = p;
}

void Lab::print() const{
    cout << name << "연구실" << endl;

    if(chief != NULL){
        cout << "실장은" << chief->getName() << endl;
    }
    else{
        cout << "실장은 현재 없습니다\n";
    }

    if(manager != NULL){
        cout << "총무는" << manager->getName() << endl;
    }
    else{
        cout << "총무는 현재 없습니다.\n";
    }
}