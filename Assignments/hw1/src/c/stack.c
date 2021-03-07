#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void push(struct stack* this, int x) {
    if (!this->size) {
        this->top = new_node(x);
        this->size++;
        return;
    }
    struct node* node = new_node(x);
    node->next = this->top;
    this->top = node;
    this->size++;
}

int pop(struct stack* this) {
    if (!this->size) {
        printf("The stack is empty\n");
        return -1;
    }
    int x = this->top->data;
    struct node* del_node = this->top;
    this->top = this->top->next;
    free(del_node);
    this->size--;
    return x;
}

struct node* new_node(int x) {
    struct node* node = malloc(sizeof(struct node));
    node->data = x;
    node->next = NULL;
    return node;
}

struct stack* new_stack() {
    struct stack* stk = malloc(sizeof(struct stack));
    stk->top = NULL;
    stk->size = 0;
    return stk;
}

void delete_stack(struct stack* stk) {
    while(stk->top) {
        struct node* del_node = stk->top;
        stk->top = stk->top->next;
        free(del_node);
    }
    free(stk);
}
