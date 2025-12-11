#include <stdio.h>
#define MAX 10
#define EMPTY -1

/*
The implementation is shown in the book
    - (pg.90 Fig. 3.15.)
*/ 

typedef struct Tree;
typedef int header, node;

typedef struct{
    char label[MAX];
    int header[MAX];
    int avail;
} NodeElement;

typedef struct{
    int node[MAX];
    int next[MAX];
    int avail;
} CellElement;

void initNode(NodeElement*);
void initCell(CellElement*);

// Inserting does not follow the axioms for Tree/PQ (Heapify)
void insert(NodeElement);

int main(){
    NodeElement nodespace;
    CellElement cellSpace;



    return 0;
}


void initNode(NodeElement* NE){
    NE->avail = EMPTY;
    for(int trav = 0; trav < MAX; trav++){
        NE->header[trav] = -1;
    }
}

void initCell(CellElement *CE){
    CE->avail = EMPTY;
    for(int trav = 0; trav < MAX; trav++){
        CE->next[trav] = EMPTY;
        CE->node[trav] = EMPTY;
    }
}

