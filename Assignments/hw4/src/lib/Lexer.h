//
//  Lexer.h
//  hw4
//
//  Created by Ernest Chu on 2020/11/18.
//

#ifndef Lexer_h
#define Lexer_h
#include <iostream>
#include <map>
#include <cctype>
#include <string>
#include <cstdio>
#include <fstream>
#include "Type.h"
#include "Num.h"
#include "Real.h"
class Lexer {
public:
    static int line;
    char peek = ' ';
    std::map<std::string, Word> words;
    std::string target;
    std::ifstream target_stream;
    void reserve(const Word& w);
    Lexer(std::string target);
    // ~Lexer();
    void readch();
    bool readch(char c);
    const Token& scan();
};

#endif /* Lexer_h */
