#include <iostream>
#include <string>
using namespace std;

class Lab{
    string name;
    Student *chief;
    Student *manager;

public:
    Lab(string n="");
    void setChief(Student *p);
    void setManager(Student *p);
    void print() const;
};