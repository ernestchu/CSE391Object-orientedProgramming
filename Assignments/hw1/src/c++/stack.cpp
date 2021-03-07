#include "stack.h"
#include <iostream>
Node::Node() {
    data = 0;
    next = NULL;
}
Node::Node(int x) {
    data = x;
    next = NULL;
}

Stack::Stack() {
    top = NULL;
    size = 0;
}
void Stack::push(int x) {
    if (!size) {
        top = new Node(x);
        size++;
        return;
    }
    Node* node = new Node(x);
    node->next = top;
    top = node;
    size++;
}
int Stack::pop() {
    if (!size) {
        std::cout << "The stack is empty\n";
        return -1;
    }
    int x = top->data;
    Node* del_node = top;
    top = top->next;
    delete del_node;
    size--;
    return x;
}
// Stack::~Stack() {
//     while(top) {
//         Node* del_node = top;
//         top = top->next;
//         delete del_node;
//     }
//     delete this;
// }
