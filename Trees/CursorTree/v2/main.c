#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Chapter 3.3 
// IMPLEMENTATIONS OF TREES

// Page 89-90

typedef int Index, Node;
typedef char Name;

typedef struct{
    Name label;
    Index header;
} nodespace;

// Similar to Heap
typedef struct{
    Node node;
    Index next;
} cellspace;

// Node leftMostChild(Node, Tree);
// void parent(Node, Tree);

int main(){

    return 0;
}


// Node leftMostChild(Node n, Tree T){
//     Index L = T.header;
//     if L = 0 return 0;
// }


// void parent(Node, Tree);