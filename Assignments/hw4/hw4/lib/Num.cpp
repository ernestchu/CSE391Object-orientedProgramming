//
//  Num.cpp
//  hw4
//
//  Created by Ernest Chu on 2020/11/18.
//

#include "Num.h"
Num::Num() : Token(Tag::NONE), value(0) {}
Num::Num(int v) : Token(Tag::NUM), value(v) {}
Num::Num(const Num& n) : Token(n), value(n.value) {} // dispatch to base copy constructor
// Num& Num::operator=(const Num& n) {
//     Token::operator=(n);
//     value = n.value;
//     return *this;
// }
Num::Num (Num&& n) : Token(std::move(n)), value(std::move(n.value)) {}
// Num& Num::operator=(Num&& n) {
//     Token::operator=(std::move(n));
//     value = std::move(n.value);
//     return *this;
// }
std::string Num::to_string() const {
    std::string val_str = std::to_string(value);
    std::string out = "Token: " + val_str + "\t(NUM)\n";
    return out;
}
