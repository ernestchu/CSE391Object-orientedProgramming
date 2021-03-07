//
//  Word.cpp
//  hw4
//
//  Created by Ernest Chu on 2020/11/18.
//

#include "Word.h"
const Word& Word::and_     = *new Word("&&",    Tag::AND);
const Word& Word::or_      = *new Word("||",    Tag::OR);
const Word& Word::eq      = *new Word("==",    Tag::EQ);
const Word& Word::ne      = *new Word("!=",    Tag::NE);
const Word& Word::le      = *new Word("<=",    Tag::LE);
const Word& Word::ge      = *new Word(">=",    Tag::GE);
const Word& Word::minus   = *new Word("minus", Tag::MINUS);
const Word& Word::True    = *new Word("true",  Tag::TRUE);
const Word& Word::False   = *new Word("false", Tag::FALSE);
const Word& Word::temp    = *new Word("t",     Tag::TEMP);
Word::Word() : Token(Tag::NONE), lexeme("none") {}
Word::Word(std::string s, int tag) : Token(tag), lexeme(s) {}
Word::Word(const Word &w) : Token(w), lexeme(w.lexeme) {}
// Word& Word::operator=(const Word &w) {
//     Token::operator=(w);
//     lexeme = w.lexeme;
//     return *this;
// }
Word::Word (Word&& w) : Token(std::move(w)), lexeme(std::move(w.lexeme)) {}
// Word& Word::operator=(Word&& w) {
//     Token::operator=(std::move(w));
//     lexeme = std::move(w.lexeme);
//     return *this;
// }
std::string tag_name(int tag) {
    switch (tag) {
        case 256:
            return "AND";
        case 257:
            return "BASIC";
        case 258:
            return "BREAK";
        case 259:
            return "DO";
        case 260:
            return "ELSE";
        case 261:
            return "EQ";
        case 262:
            return "FALSE";
        case 263:
            return "GE";
        case 264:
            return "ID";
        case 265:
            return "IF";
        case 266:
            return "INDEX";
        case 267:
            return "LE";
        case 268:
            return "MINUS";
        case 269:
            return "NE";
        case 270:
            return "NUM";
        case 271:
            return "OR";
        case 272:
            return "REAL";
        case 273:
            return "TEMP";
        case 274:
            return "TRUE";
        case 275:
            return "WHILE";
        case 0:
            return "NONE";
        default:
            return "Undef";
    }
}
std::string Word::to_string() const {
    std::string tag_str = tag_name(tag);
    std::string out = "Token: " + lexeme + "\t(" + tag_str + ")\n";
    return out;
}
