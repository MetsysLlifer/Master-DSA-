#include <stdio.h>
#define MAX 10

// Chapter 3.3 
// IMPLEMENTATIONS OF TREES

// Page 85-86

typedef int Tree[MAX];
typedef int Node;

Node rightSibling(Node, Tree);
void displaySingleNode(Node);

int main(){
    Tree T = {0, 1, 1, 2, 2, 5, 5, 5, 3, 3};
    displaySingleNode(rightSibling(1, T));
}

Node rightSibling(Node n, Tree T){
    Node i, parent;
    parent = T[n];
    for(i = n+1; i < MAX && T[i] != parent; i++){}
    return (i != MAX) ? i: 0;
}

void displaySingleNode(Node n){
    printf("Node [%d]", n);
}