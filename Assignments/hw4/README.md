# Assignment 4

## Lex

### File structue 

```sh
.
├── README.md
├── hw4-oop-2020f.pdf
└── src
    ├── lib
    │   ├── Lexer.cpp
    │   ├── Lexer.h
    │   ├── Num.cpp
    │   ├── Num.h
    │   ├── Real.cpp
    │   ├── Real.h
    │   ├── Tag.cpp
    │   ├── Tag.h
    │   ├── Token.cpp
    │   ├── Token.h
    │   ├── Type.cpp
    │   ├── Type.h
    │   ├── Word.cpp
    │   └── Word.h
    ├── makefile
    ├── scanner.cpp
    └── test
        ├── test1.cpp
        └── test2.cpp
```

### Instructions
[hw4-oop-2020f.pdf](hw4-oop-2020f.pdf)

### Build and run
```sh
cd src
make
./scanner test/test1.cpp
./scanner test/test2.cpp
make clean
```
