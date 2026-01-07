#include "util.h"


void makeNull(QueueType* Q) {
    if (*Q != NULL) {
        while ((*Q)->front != NULL) {
            record toDelete = (*Q)->front;
            (*Q)->front = (*Q)->front->next;
            free(toDelete);
        }
    } else {
        *Q = (QueueType)malloc(sizeof(struct QueueRecord));
        if (*Q == NULL) {
            printf("Memory allocation failed\n");
            return;
        }
    }

    // Reset pointers to Safe Empty State
    (*Q)->front = NULL;
    (*Q)->rear = NULL;
}

bool empty(QueueType Q){
    return Q->front == NULL? true: false;
}

char front(QueueType Q){
    return !empty(Q)?Q->front->value: '\0';
}

void enqueue(QueueType* Q, char value){
    record newNode = (record)malloc(sizeof(struct node));

    if(newNode == NULL){
        printf("Malloc failed!\n");
        return;
    }

    newNode->value = value;
    newNode->next = NULL;

    // if the queue is empty, then both pointers (front, rear) will point to the newNode
    if(empty(*Q)){
        (*Q)->front = newNode;
    // if the queue is not empty, then insert it next to the rear
    }else{
        (*Q)->rear->next = newNode;
    }

    (*Q)->rear = newNode;
}

void dequeue(QueueType* Q){
    if(!empty(*Q)){
        record toDelete = (*Q)->front;
        (*Q)->front = (*Q)->front->next;

        if((*Q)->front == NULL){
            (*Q)->rear = NULL;
        }

        free(toDelete);
    }
}

// Debug
void checkNodes(QueueType Q){
    record trav = Q->front;
    printf("Queue: ");
    while(trav != NULL){
        printf("%c%s", trav->value, trav->next!=NULL? " <- ": "\n");
        trav = trav->next;
    }
}