#ifndef __FORM_H__
#define __FORM_H__
#include <iostream>
#include <sstream>
using namespace std;

struct Bound_form;
class Form {
    friend ostream& operator<<(ostream&, const Bound_form&);
    int prc; // precision
    ios_base::fmtflags fmt; // format. general, scientific, fixed
public:
    explicit Form(int p = 6) : prc(p), fmt(ios_base::dec) {}
    Bound_form operator()(double d) const; // make a Bound_form for *this and d
    Form& scientific();
    Form& fixed();
    Form& precision(int p);
};
struct Bound_form {
    const Form& f;
    double val;
    Bound_form(const Form& ff, double v) : f(ff), val(v) {}
};
ostream& operator<<(ostream& os, const Bound_form& bf);

#endif
