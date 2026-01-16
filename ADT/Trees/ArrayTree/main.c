#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 63

// 63 is the maximum value to display complete tree in the terminal. Beyond this number will cause chatic pattern in the terminal.

// Chapter 3.3 
// IMPLEMENTATIONS OF TREES

// Page 85-86

typedef int Tree[MAX];
typedef int Node;

Node rightSibling(Node, Tree);
void displaySingleNode(Node);
void visualizeTree(Tree);
void testLength(Tree T);
void addInitValue(Tree T);


int main(){
    // Tree T = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Tree T;
    addInitValue(T);
    
    displaySingleNode(rightSibling(1, T));
    visualizeTree(T);
    // testLength(T);

    return 0;
}


Node rightSibling(Node n, Tree T){
    Node i, parent;
    parent = T[n];
    for(i = n+1; i < MAX && T[i] != parent; i++){}
    return (i != MAX) ? i: 0;
}

void displaySingleNode(Node n){
    printf("Node [%d]\n", n);
}

void visualizeTree(Tree T) {
    int levels = (int)ceil(log2(MAX + 1)); // Calculate total height roughly

    int index = 0;
    for (int l = 0; l < levels; l++) {
        // Calculate number of nodes in this level (2^l)
        int nodesInLevel = (int)pow(2, l);
        
        // Calculate spacing:
        // The deeper we are, the tighter the spacing.
        // Formula: Space = 2^(height - current_level + 1)
        int space = (int)pow(2, levels - l + 1);
        int initialOffset = (int)pow(2, levels - l) - 1;

        // Print initial offset for the row
        printf("%*s", initialOffset, "");

        for (int k = 0; k < nodesInLevel; k++) {
            if (index < MAX) {
                // %-2d aligns the number to left if it's 2 digits
                // spacing is used for the padding AFTER the number
                printf("%-2d", T[index]); 
                
                // Add spacing between nodes, but not after the last one
                if(k < nodesInLevel - 1) {
                   printf("%*s", space - 2, ""); // -2 accounts for the digits
                }
                index++;
            }
        }
        printf("\n\n"); // Double newline prevents squashing
    }
}

void addInitValue(Tree T){
    for(int trav = 0; trav < MAX; trav++){
        T[trav] = trav;
    }
}

void testLength(Tree T){
    int current = 11;
    int length = -1;
    for(int trav = current; trav < MAX; trav=trav*2+1) length++;
    length = (length > 0)? pow(2, length): 1;
    printf("current length: %d", length);
}