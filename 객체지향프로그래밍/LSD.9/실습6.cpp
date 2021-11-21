#include <iostream>
using namespace std;

class String{
    char *s;
public:
    String(const char *p){
        cout << "String() 생성자" << endl;
        s = new char[strlen(p)+1];
        strcpy(s, p);
    }
    ~String(){
        cout << "String() 소멸자" << endl;
        delete[] s;
    }
    virtual void display(){
        cout << s;
    }
};

class MyString : public String {
    char *header;
public:
    MyString(const char *h, const char *p) : String(p) {
        cout << "MyString() 생성자" << endl;
        header = new char[strlen(h)+1];
        strcpy(header, h);
    }
    ~MyString(){
        cout << "MyString() 소멸자" << endl;
        delete[] header;
    }
    void display(){
        cout << header;
        String::display();
        cout << header << endl;
    }
};

int main(void){
    String *p = new MyString("--","Hello World!");
    p->display();
    delete p;

    return 0;
}