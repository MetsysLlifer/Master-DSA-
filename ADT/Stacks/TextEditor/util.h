#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    char word[10];
    int count;
} Stack;

void makeNull(Stack*);
bool empty(Stack);
bool full(Stack);
char top(Stack);
void push(Stack*, char);
void pop(Stack*);
void storeText(Stack*, char*);  