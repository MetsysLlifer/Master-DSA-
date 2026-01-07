#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct node{
    char value;
    struct node* next;
} *record;

typedef struct QueueRecord{
    record front;
    record rear;
} *QueueType;

void makeNull(QueueType*);
bool empty(QueueType);
char front(QueueType);
void enqueue(QueueType*, char);
void dequeue(QueueType*);

// Debug
void checkNodes(QueueType);