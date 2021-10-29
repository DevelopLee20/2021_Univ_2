#include <iostream>
using namespace std;

class Complex{
private:
    double real;
    double imag;

public:
    Complex();
    Complex(double a, double b);
    ~Complex();

    double getReal();
    double getlmag();
    Complex add(const Complex &c);
    void print();
};