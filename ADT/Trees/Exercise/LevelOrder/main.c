#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 10
#define EMPTY -1

/* Exercise
    3.10 (P.105)
        The level-order listing of the nodes of a tree first lists the root, then
all nodes of depth 1, then all nodes of depth 2, and so on. Nodes at
the same depth are listed in left-to-right order. Write a program to
list the nodes of a tree in level-order.
*/

// BT

typedef int Index;

typedef struct{
    int elements[MAX_NODES];
    int lastIndex;
} BT;


void levelOrderBT(BT);

int main(){
    BT BT = {{1, 2, 3, 4, 5, 6, 7 ,8, 9, 10}, 9};

    levelOrderBT(BT);
    return 0;
}

void levelOrderBT(BT T){
    // Level-order listing of the nodes of a binary tree
    // is just traversing from first index to its last index
    printf("level-order list (BT): ");
    for(Index trav = 0; trav <= T.lastIndex; trav++){
        printf("%d ", T.elements[trav]);
    }
}