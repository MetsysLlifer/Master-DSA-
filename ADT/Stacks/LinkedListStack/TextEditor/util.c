#include "util.h"


void makeNull(Stack* S){
    *S = NULL;
}

bool empty(Stack S){
    return S == NULL? true: false;
}

char top(Stack S){
    return S->value;
}

void pop(Stack* S){
    if(!empty(*S)){
        Stack node = *S;
        *S = (*S)->next;
        free(node);
    }
}

void push(Stack* S, char value){
    Stack newNode = (Stack)malloc(sizeof(struct node));
    
    if(newNode == NULL){
        printf("Malloc failed\n");
        return;
    }

    newNode->value = value;
    newNode->next = *S;
    *S = newNode;
}

// Pushes input value onto Stack
void storeText(Stack* S, char* input){
    int trav = 0;
    while(input[trav] != '\0'){
        if(input[trav] == '@'){
            makeNull(S);
            ++trav;
        } else if(input[trav] == '#'){
            pop(S);
            ++trav;
        }else push(S, input[trav++]);
    }
}