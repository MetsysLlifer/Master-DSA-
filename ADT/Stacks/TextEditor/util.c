#include "util.h"


void makeNull(Stack* S){
    S->count = -1;
}

bool empty(Stack S){
    return S.count == -1? true: false;
}

bool full(Stack S){
    return S.count + 1 == MAX? true: false;
}

char top(Stack S){
    return S.word[S.count];
}

void pop(Stack* S){
    if(!empty(*S)){
        --S->count;
    }
}

void push(Stack* S, char c){
    if(!full(*S)){
        S->word[++S->count] = c;
    }
}

// Pushes input value onto Stack
void storeText(Stack* S, char* input){
    int trav = 0;
    while(!full(*S) && input[trav] != '\0'){
        if(input[trav] == '@'){
            makeNull(S);
            ++trav;
        } else if(input[trav] == '#'){
            pop(S);
            ++trav;
        }else push(S, input[trav++]);
    }
}