#include <stdio.h>
#include "headers/tree.h"
#include "headers/base.h"
#include <math.h>

void initNS(Nodespace*);
void initVH(VirtualHeap*);
void initTree(Tree*);

void insert(element, Tree*, Nodespace*, VirtualHeap*);


int main(){
    VirtualHeap VH;
    Nodespace NS;
    Tree T;

    // Testing the parent presentation
    // and the use of right_sibling
    Node A[MaxSize] = {0, 1, 1, 2, 2, 5, 5, 5, 3, 3}; // parent representation


    initNS(&NS);
    initVH(&VH);
    initTree(&T);
    test();


    return 0;
}

void initNS(Nodespace *NS){
    for(int trav = 0; trav < MaxSize; trav++){
        NS->nodes[trav].next = Empty;
    }
}

void initVH(VirtualHeap *VH){
    for(int trav = 0; trav < MaxSize; trav++){
        VH->slots[trav].next = Empty;
    }
    VH->avail = Empty;
}

void initTree(Tree *T){
    *T = Empty;
}

void insert(element, Tree*, Nodespace*, VirtualHeap*){

}


