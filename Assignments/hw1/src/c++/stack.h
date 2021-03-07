#ifndef __STACK_H__
#define __STACK_H__

class Stack;
class Node {
private:
    int data;
    Node* next;
public:
    Node();
    Node(int x);
    friend class Stack;
};

class Stack {
private:
    Node* top;
    int size;
public:
    Stack();
    void push(int x);
    int pop();
    //~Stack();
};

#endif
