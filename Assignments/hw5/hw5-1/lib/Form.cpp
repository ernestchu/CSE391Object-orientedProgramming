#include "Form.h"

Form& Form::scientific() {
    fmt = ios_base::scientific;
    return *this;
}
Form& Form::fixed() {
    fmt = ios_base::fixed;
    return *this;
}
Form& Form::precision(int p) {
    prc = p;
    return *this;
}

Bound_form Form::operator() (double d) const {return Bound_form(*this, d);}
ostream& operator<<(ostream& os, const Bound_form& bf) {
    ostringstream s;
    s.precision(bf.f.prc);
    s.setf(bf.f.fmt, std::ios_base::floatfield);
    s << bf.val;
    return os << s.str();
}
