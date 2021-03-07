//
//  Real.h
//  hw4
//
//  Created by Ernest Chu on 2020/11/18.
//

#ifndef Real_h
#define Real_h
#include "Token.h"
class Real : public Token {
public:
    Real();
    Real(float v);
    Real(const Real& n);
    Real& operator=(const Real& n) = delete;
    Real (Real&& n);
    Real& operator=(Real&& n) = delete;
    std::string to_string() const;
    const float value;
};

#endif /* Real_h */
