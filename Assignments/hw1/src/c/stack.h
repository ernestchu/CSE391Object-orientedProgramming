#ifndef __STACK_H__
#define __STACK_H__

#define STACK_SIZE 100

struct node {
    int data;
    struct node* next;
};

struct stack {
    struct node* top;
    int size;
};

extern void push(struct stack* this, int x);
extern int pop(struct stack* this);
extern struct stack* new_stack();
extern void delete_stack(struct stack* stk);


struct node* new_node(int x);

#endif
