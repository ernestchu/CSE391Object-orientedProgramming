//
//  Token.cpp
//  hw4
//
//  Created by Ernest Chu on 2020/11/18.
//

#include "Token.h"
Token::Token() : tag(Tag::NONE) {}
Token::Token(int tag) : tag(tag) {}
Token::Token(const Token& t) : tag(t.tag) {}
// Token& Token::operator=(const Token& t) {
//     tag = t.tag;
//     return *this;
// }
Token::Token (Token&& t) : tag(std::move(t.tag)) {}
// Token& Token::operator=(Token&& t) {
//     tag = std::move(t.tag);
//     return *this;
// }
std::string Token::to_string() const {
    std::string tag_str(1, tag);
    std::string out = "Token: " + tag_str + "\t(" + tag_str + ")\n";
    return out;
}
