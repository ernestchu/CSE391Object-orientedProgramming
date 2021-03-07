//
//  Real.cpp
//  hw4
//
//  Created by Ernest Chu on 2020/11/18.
//

#include "Real.h"
Real::Real() : Token(Tag::NONE), value(0) {}
Real::Real(float v) : Token(Tag::REAL), value(v) {}
Real::Real(const Real& n) : Token(n), value(n.value) {} // dispatch to base copy constructor
// Real& Real::operator=(const Real& n) {
//     Token::operator=(n);
//     value = n.value;
//     return *this;
// }
Real::Real (Real&& n) : Token(std::move(n)), value(std::move(n.value)) {}
// Real& Real::operator=(Real&& n) {
//     Token::operator=(std::move(n));
//     value = std::move(n.value);
//     return *this;
// }
std::string Real::to_string() const {
    std::string val_str = std::to_string(value);
    std::string out = "Token: " + val_str + "\t(REAL)\n";
    return out;
}
