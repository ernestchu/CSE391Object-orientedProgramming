//
//  Complex.cpp
//  hw3
//
//  Created by Ernest Chu on 2020/11/3.
//
#include "Complex.h"
Complex::Complex(const double re, const double im) : real(re), imag(im) {}
Complex::Complex(const Complex& c) : real(c.real), imag(c.imag) {}
Complex& Complex::operator=(const Complex& c) {
    real = c.real;
    imag = c.imag;
    return *this;
}

Complex Complex::Polar(const double leng, const double arg) {
    real = leng * cos(arg);
    imag = leng * sin(arg);
    return *this;
}

double Complex::Real() {
    return real;
}
double Complex::Image() {
    return imag;
}
double Complex::Norm() {
    return (pow(real, 2)+pow(imag, 2));
}
double Complex::Abs() {
    return sqrt(pow(real, 2)+pow(imag, 2));
}
double Complex::Arg() {
    return atan(imag/real);
}

Complex Complex::operator++() {
    real++;
    imag++;
    return *this;
}
Complex Complex::operator++(int) {
    Complex* t = new Complex(*this);
    real++;
    imag++;
    return *t;
}
Complex Complex::operator--() {
    real--;
    imag--;
    return *this;
}
Complex Complex::operator--(int) {
    Complex* t = new Complex(*this);
    real--;
    imag--;
    return *t;
}

Complex::~Complex() {}

Complex Polar(const double leng, const double arg) {
    double real = leng * cos(arg);
    double imag = leng * sin(arg);
    Complex* t = new Complex(real, imag);
    return *t;
}
double Norm(const Complex& x) {
    return (pow(x.real, 2)+pow(x.imag, 2));
}
double Abs(const Complex& x) {
    return sqrt(pow(x.real, 2)+pow(x.imag, 2));
}
double Arg(const Complex& x) {
    return atan(x.imag/x.real);
}
Complex operator+(const Complex& x, const Complex& y) {
    Complex* t = new Complex(x);
    t->real += y.real;
    t->imag += y.imag;
    return *t;
}
Complex operator-(const Complex& x, const Complex& y) {
    Complex* t = new Complex(x);
    t->real -= y.real;
    t->imag -= y.imag;
    return *t;
}
Complex operator*(const Complex& x, const Complex& y) {
    Complex* t = new Complex();
    t->real = x.real*y.real-x.imag*y.imag;
    t->imag = x.real*y.imag+x.imag*y.real;
    return *t;
}
Complex operator/(const Complex& x, const Complex& y) {
    if ((y.real+y.imag) == 0) {
        std::cout << "Zero Division\n";
        exit(EXIT_FAILURE);
    }
    Complex* t = new Complex();
    double term = pow(y.real, 2)+pow(y.imag, 2);
    t->real = (x.real*y.real + x.imag*y.imag)/term;
    t->imag = (x.imag*y.real - x.real*y.imag)/term;
    return *t;
}
Complex operator+=(Complex& x, const Complex& y) {
    x.real += y.real;
    x.imag += y.imag;
    return x;
}
Complex operator-=(Complex& x, const Complex& y) {
    x.real -= y.real;
    x.imag -= y.imag;
    return x;
}
Complex operator*=(Complex& x, const Complex& y) {
    double x_re = x.real;
    x.real = x.real*y.real-x.imag*y.imag;
    x.imag = x_re*y.imag+x.imag*y.real;
    return x;
}
Complex operator/=(Complex& x, const Complex& y) {
    if ((y.real+y.imag) == 0) {
        std::cout << "Zero Division\n";
        exit(EXIT_FAILURE);
    }
    double term = pow(y.real, 2)+pow(y.imag, 2);
    double x_re = x.real;
    x.real = (x.real*y.real + x.imag*y.imag)/term;
    x.imag = (x.imag*y.real - x_re*y.imag)/term;
    return x;
}
bool operator==(const Complex& x, const Complex& y) {
    return (x.real==y.real && x.imag==y.imag);
}
bool operator!=(const Complex& x, const Complex& y) {
    return (x.real!=y.real || x.imag!=y.imag);
}
ostream& operator<<(ostream& o, const Complex& x) {
    o << "(" << x.real << ',' << x.imag << ')';
    return o;
}



