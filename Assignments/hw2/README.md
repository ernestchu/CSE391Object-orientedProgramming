# Assignment 2

## Tarball

### File structue 

```sh
.
├── README.md
├── hw2-oop-2020f.pdf
└── src
    ├── lib
    │   ├── tar.cpp
    │   ├── tar.h
    │   ├── utils.cpp
    │   └── utils.h
    ├── makefile
    ├── mytar.cpp
    └── test
        ├── hw1.tar
        ├── linktest.tar
        └── test.tar
```

### Instructions
[hw2-oop-2020f.pdf](hw2-oop-2020f.pdf)

### Build and run
```sh
cd src
make
./mytar test/test.tar
./mytar test/linktest.tar
./mytar test/hw1.tar
make clean
```
