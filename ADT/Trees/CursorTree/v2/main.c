#include <stdio.h>
#include <stdlib.h>
#define MAX 10


/* IMPLEMENTATIONS OF TREES (Chapter 3.3)
The implementation is shown in the book
    - (pg.90 Fig. 3.15.)
*/ 

// CAUTION!!!
// This does not follow the axioms for PQ/Trees
// The only goal here is to connect the nodes to its proper ancestors and descendants

#include <stdio.h>
#define MAX 10
#define EMPTY -1




typedef int Tree;
typedef int header, node;
typedef char label;

typedef struct{
    char label;
    int header;
} NodeElement;

typedef struct{
    NodeElement nodes[MAX];
    int avail;
} NodeSpace;

typedef struct{
    int node;
    int next;
} CellElement;

typedef struct{
    CellElement cells[MAX];
    int avail;
} CellSpace;

void initNode(NodeSpace*);
void initCell(CellSpace*);

// Debugging (displays all headers (nodespace) and cells (cellspace))
void displayNodes(NodeSpace);
void displayCells(CellSpace);


void addNode();
void addChild();


NodeSpace nodespace;
CellSpace cellspace;

int main(){
    initCell(&cellspace);
    initNode(&nodespace);

    displayNodes(nodespace);
    displayCells(cellspace);

    return 0;
}

void initNode(NodeSpace* NE){
    NE->avail = EMPTY;
    for(int trav = 0; trav < MAX; trav++){
        NE->nodes[trav].header = -1;
        NE->nodes[trav].label = ' ';
    }
}

void initCell(CellSpace *CE){
    CE->avail = EMPTY;
    for(int trav = 0; trav < MAX; trav++){
        CE->cells[trav].next = trav+1;
        CE->cells[trav].node = EMPTY;
    }
    CE->cells[MAX-1].next = EMPTY;
}


// Debugging
void displayNodes(NodeSpace NS){
    printf("Nodespace [header]: ");
    for(int trav = 0; trav < MAX; trav++){
        printf("%d ", NS.nodes[trav].header);
    }
    printf("\n");
}

void displayCells(CellSpace CE){
    printf("Cellspace [next]: ");
    for(int trav = 0; trav < MAX; trav++){
        printf("%d ", CE.cells[trav].next);
    }
    printf("\n");
}


// Add nodes
void addNode(){

}