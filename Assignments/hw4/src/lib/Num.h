//
//  Num.h
//  hw4
//
//  Created by Ernest Chu on 2020/11/18.
//

#ifndef Num_h
#define Num_h
#include "Token.h"
class Num : public Token {
public:
    Num();
    Num(int v);
    Num(const Num& n);
    Num& operator=(const Num& n) = delete;
    Num (Num&& n);
    Num& operator=(Num&& n) = delete;
    std::string to_string() const;
    const int value;
};

#endif /* Num_h */
