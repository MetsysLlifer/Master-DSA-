#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct node{
    char value;
    struct node* next;
} *Stack;

void makeNull(Stack*);
bool empty(Stack);
char top(Stack);
void push(Stack*, char);
void pop(Stack*);
void storeText(Stack*, char*);  