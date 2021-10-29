#include <iostream>
#include <string>
using namespace std;

class Student{
private:
    string name;
    string telephone;

public:
    Student(const string n="", const string t="");
    string getTelephone() const;
    void setTelephone(const string t);
    string getName() const;
    void setName(const string n);
};