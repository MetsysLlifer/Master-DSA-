#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 10
#define EMPTY -1

/* Exercise
    3.9 (P.104)
        Write programs traverse a binary tree in
        - a) preorder,
        - b) postorder,
        - c) inorder.
*/

// BT

typedef int Index;

typedef struct{
    int elements[MAX_NODES];
    int lastIndex;
} BT;

void preorder(BT, Index);
void postorder(BT, Index);
void inorder(BT, Index);

int main(){
    BT T = {{1, 2, 3, 4, 5, 6, 7 ,8, 9, 10}, 9};
    printf("Preorder: ");
    preorder(T, 0);

    printf("\nPostorder: ");
    postorder(T, 0);

    printf("\nInorder: ");
    inorder(T, 0);


    // Pre, Post, and In orders (Completed)

    return 0;
}

void preorder(BT T, Index parent){
    if(parent <= T.lastIndex){
        printf("%d ", T.elements[parent]);
        for(Index child = 1; child <= 2; child++){
            preorder(T, parent*2+child);
        }
    }
}

void postorder(BT T, Index parent){
    if(parent <= T.lastIndex){
        for(Index child = 1; child <= 2; child++){
            postorder(T, parent*2+child);
        }
        printf("%d ", T.elements[parent]);
    }
}

void inorder(BT T, Index parent){
    if(parent <= T.lastIndex){
        Index child = parent*2+1;
        inorder(T, child++);
        printf("%d ", T.elements[parent]);
        inorder(T, child);
    }
}