#include <iostream>
using namespace std;

class MyString{
private:
    char *pBuf;

public:
    MyString(const char *s = NULL);
    MyString(MyString &s);
    ~MyString();

    void print();
    int getSize();
};