#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10


typedef struct QueueRecord{
    char nodes[MAX];
    int front;
    int rear;
} QueueType;

void makeNull(QueueType*);
bool empty(QueueType);
bool full(QueueType);
char front(QueueType);
void enqueue(QueueType*, char);
void dequeue(QueueType*);

// Debug
void checkNodes(QueueType);