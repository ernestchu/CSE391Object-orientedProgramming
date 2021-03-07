//
//  Token.h
//  hw4
//
//  Created by Ernest Chu on 2020/11/18.
//

#ifndef Token_h
#define Token_h
#include <string>
#include "Tag.h"
class Token {
public:
    Token();
    Token(int tag);
    Token(const Token& t);
    Token& operator=(const Token& t) = delete;
    Token (Token&& t);
    Token& operator=(Token&& t) = delete;
    virtual std::string to_string() const;
    const int tag;
};

#endif /* Token_h */
