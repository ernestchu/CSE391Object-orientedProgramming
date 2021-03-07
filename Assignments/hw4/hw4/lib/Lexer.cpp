//
//  Lexer.cpp
//  hw4
//
//  Created by Ernest Chu on 2020/11/18.
//

#include "Lexer.h"
int Lexer::line = 1;
void Lexer::reserve(const Word& w) {
    words.insert({w.lexeme, w});
}
Lexer::Lexer(std::string target) : target(target) {
    target_stream.open(target, std::ifstream::in);
    reserve(*new Word("if",      Tag::IF));
    reserve(*new Word("else",    Tag::ELSE));
    reserve(*new Word("while",   Tag::WHILE));
    reserve(*new Word("do",      Tag::DO));
    reserve(*new Word("break",   Tag::BREAK));
    reserve(Word::True);
    reserve(Word::False);
    reserve(Type::Int);
    reserve(Type::Char);
    reserve(Type::Bool);
    reserve(Type::Float);
}
void Lexer::readch() {
    int i = target_stream.get();
    if (i != -1)
        peek = (char) i;
    else {
        std::cout << "End of file reached\n";
        exit(0);
    }
}
bool Lexer::readch(char c) {
    readch();
    if (peek != c)
        return false;
    peek = ' ';
    return true;
}
const Token& Lexer::scan() {
    for (;; readch()) {
        if (peek == ' ' || peek == '\t')
            continue;
        else if (peek == '\n')
            line += 1;
        else
            break;
    }
    switch (peek) {
        case '&':
            if (readch('&'))
                return Word::and_;
            else
                return *new Token('&');
        case '|':
            if (readch('|'))
                return Word::or_;
            else
                return *new Token('|');
        case '=':
            if (readch('='))
                return Word::eq;
            else
                return *new Token('=');
        case '!':
            if (readch('!'))
                return Word::ne;
            else
                return *new Token('!');
        case '<':
            if (readch('<'))
                return Word::le;
            else
                return *new Token('<');
        case '>':
            if (readch('>'))
                return Word::ge;
            else
                return *new Token('>');

    }
    //read numbers
    if (isdigit(peek)) {
        int v = 0;
        do {
            v = 10*v + peek-48;
            readch();
        } while (isdigit(peek));
        if (peek != '.')
            return *new Num(v);
        float x = v;
        float d = 10;
        while (true) {
            readch();
            if (!isdigit(peek))
                break;
            x += (peek-48)/d;
            d *= 10;
        }
        return *new Real(x);
    }
    //read variable name
    if (isalpha(peek)) {
        std::string s = "";
        do {
            s.push_back(peek);
            readch();
        } while (isdigit(peek) || isalpha(peek) || peek=='_');
        try {
            Word& w = words.at(s);
            return w;
        }
        catch (const std::out_of_range& e) {
            Word& word = *new Word(s, Tag::ID);
            words.insert({s, word});
            return word;
        }
    }
    Token& tok = *new Token(peek);
    peek = ' ';
    return tok;
}
