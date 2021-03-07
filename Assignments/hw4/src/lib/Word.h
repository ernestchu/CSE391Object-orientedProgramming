//
//  Word.h
//  hw4
//
//  Created by Ernest Chu on 2020/11/18.
//

#ifndef Word_h
#define Word_h
#include "Token.h"
class Word : public Token {
public:
    Word();
    Word(std::string s, int tag);
    Word(const Word& w);
    Word& operator=(const Word& w) = delete;
    Word (Word&& n);
    Word& operator=(Word&& n) = delete;
    std::string to_string() const;
    const std::string lexeme;
    static const Word &and_, &or_, &eq, &ne, &le, &ge, &minus, &True, &False, &temp;
};

#endif /* Word_h */
