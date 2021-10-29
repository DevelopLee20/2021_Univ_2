#include "실습13_complex.h"

Complex::Complex(){
    real = 0;
    imag = 0;
}

Complex::Complex(double a, double b){
    real = a;
    imag = b;
}

Complex::~Complex(){
}

double Complex::getReal(){
    return(real);
}

double Complex::getlmag(){
    return(imag);
}

Complex Complex::add(const Complex &c){
    Complex temp;
    temp.real = this->real + c.real;
    temp.imag = this->imag + c.imag;

    return temp;
}

void Complex::print(){
    cout << real << "+" << imag << "i" << endl;
}