#ifndef __VECTOR_H__
#define __VECTOR_H__
#include "Trace.h"
#include <iostream>
using std::cout;
using std::endl;

// general form
template<typename T>
class vector {
    static inline int count = 0;
    T* v;
    int sz;
public:
    vector(int size = 0) : sz(size) {
        TRACE(dummy, "vector<T>::vector(int)");
        v = new T[sz];
        cout << "   count = "<< ++count << endl;
    }
    ~vector() {
        TRACE(dummy, "vector<T>::~vector()");
        delete v;
        cout << "   count = "<< count-- << endl;
    }

    T& elem(int i) {return v[i];}
    T& operator[](int i) {return v[i];}
};
//specialization
template<>
class vector<void*> {
    static inline int count = 0;
    void** p;
    int sz;
public:
    vector(int size = 0) : sz(size) {
        TRACE(dummy, "vector<void*>::vector(int)");
        p = new void*[sz];
        cout << "   count = "<< ++count << endl;
    }
    ~vector() {
        TRACE(dummy, "vector<void*>::~vector()");
        delete p;
        cout << "   count = "<< count --<< endl;
    }
    void*& elem(int i) {return p[i];}
    void*& operator[](int i) {return p[i];}
};
// partial specialization
template<typename T>
class vector<T*> : private vector<void*> {
public:
    typedef vector<void*> Base;
    vector(int size = 0) : Base(size) {
        TRACE(dummy, "vector<T*>::vector(int)");
    }
    ~vector() {
        TRACE(dummy, "vector<T*>::~vector()");
    }

    T*& elem(int i) {return (T*&)Base::elem(i);}
    T*& operator[](int i) {return (T*&)Base::operator[](i);}
};

#endif
