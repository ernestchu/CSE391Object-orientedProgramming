//
//  Type.h
//  hw4
//
//  Created by Ernest Chu on 2020/11/18.
//

#ifndef Type_h
#define Type_h
#include "Word.h"
class Type : public Word {
public:
    Type();
    Type(std::string s, int tag, int w);
    Type(const Type& t);
    Type& operator=(const Type& t) = delete;
    Type (Type&& t);
    Type& operator=(Type&& t) = delete;
    static const Type &Int, &Float, &Char, &Bool;
    // static bool numeric(const Type& p);
    // static Type& max(const Type& p1, const Type& p2);
    const int width;
    // friend bool operator==(const Type& p1, const Type& p2);
};


#endif /* Type_h */
