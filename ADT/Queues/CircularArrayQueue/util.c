#include "util.h"


void makeNull(QueueType* Q) {
    Q->front = 0;
    Q->rear = -1;
}

bool empty(QueueType Q){
    return (Q.rear+1) % MAX == Q.front? true: false;
}

bool full(QueueType Q){
    return (Q.rear+2) % MAX == Q.front? true: false;
}

char front(QueueType Q){
    return !empty(Q)?Q.nodes[Q.front]: '\0';
}

void enqueue(QueueType* Q, char value){
    if(!full(*Q)){
        Q->nodes[++Q->rear] = value;
    }
}

void dequeue(QueueType* Q){
    if(!empty(*Q)){
        ++Q->front;
    }
}

// Debug
void checkNodes(QueueType Q){
    int trav = Q.front;
    printf("Queue: ");
    while(trav % MAX != Q.rear + 1){
        printf("%c%s", Q.nodes[trav], (trav % MAX != Q.rear)? " -> ": "\n");
        ++trav;
    }
}