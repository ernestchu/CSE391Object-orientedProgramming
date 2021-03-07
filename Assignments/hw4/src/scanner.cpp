//
//  main.cpp
//  hw4
//
//  Created by Ernest Chu on 2020/11/18.
//

#include <iostream>
#include "lib/Lexer.h"
int main(int argc, const char * argv[]) {
    if (argc==1) {
        std::cout << "No file to be scan\n";
        return 0;
    }
    std::string target(argv[1]);
    Lexer lexer(target);
    while (true) {
        const Token& t = lexer.scan();
        std::cout << t.to_string();
    }
    return 0;
}
