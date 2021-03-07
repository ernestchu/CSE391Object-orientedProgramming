//
//  Type.cpp
//  hw4
//
//  Created by Ernest Chu on 2020/11/18.
//

#include "Type.h"
const Type& Type::Int     = *new Type("int",   Tag::BASIC, 4);
const Type& Type::Float   = *new Type("float", Tag::BASIC, 8);
const Type& Type::Char    = *new Type("char",  Tag::BASIC, 1);
const Type& Type::Bool    = *new Type("bool",  Tag::BASIC, 1);
Type::Type() : Word(), width(0) {}
Type::Type(std::string s, int tag, int w) : Word(s, tag), width(w) {}
Type::Type(const Type &t) : Word(t), width(t.width) {}
// Type& Type::operator=(const Type &t) {
//     Word::operator=(t);
//     width = t.width;
//     return *this;
// }
Type::Type (Type&& t) : Word(std::move(t)), width(std::move(t.width)) {}
// Type& Type::operator=(Type&& t) {
//     Word::operator=(std::move(t));
//     width = std::move(t.width);
//     return *this;
// }

// bool Type::numeric(const Type& p) {
//     if (p == Type::Char || p == Type::Int || p == Type::Float)
//         return true;
//     else
//         return false;
// }
// Type& Type::max(const Type& p1, const Type& p2) {
//     if (!numeric(p1) || !numeric(p2))
//         return *nullptr;
//     else if (p1 == Type::Float || p2 == Type::Float)
//         return Type::Float;
//     else if (p1 == Type::Int || p2 == Type::Int)
//         return Type::Int;
//     else
//         return Type::Char;
// }
// bool operator==(const Type& p1, const Type& p2) {
//     if (p1.lexeme==p2.lexeme)
//         return true;
//     return false;
// }
