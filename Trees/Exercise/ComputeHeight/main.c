#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 10

/* Exercise
    3.2 (P.103)
        Write programs to compute the height of a tree using each of the
three tree representations of Section 3.3.
*/

/* Implementations of Tress
    - An Array Representation of Trees
        - parent representation
    - Representation of Trees by Lists of Children
        - linked-list representation (2 Versions)
    - Binary Trees
*/


// LINKED-LIST
typedef struct ListElement {
    int nodeIndex;              // The integer ID of the child
    struct ListElement* next;   // The pointer to the next sibling
} ListElement;

typedef struct {
    ListElement* header[MAX_NODES + 1]; // Array of pointers to the first child of each node
    int root;                       // Stores the root node index
} Tree;

// BT
typedef struct{
    int elements[MAX_NODES];
    int lastIndex;
} BT;


// parent representation
void depthPP(int[], int);

// linked-list representation Version 1
void initTree(Tree* T, int rootIndex);
ListElement* createNode(int nodeIndex);
void addChild(Tree* T, int parentIndex, int childIndex);
void printChildren(Tree T, int parentIndex); // checks if the tree is working (debug)
int depthLL(Tree, int rootIndex);

// Binary Tree;
void depthBT(BT);

int main(){
    // Parent Presentation (PP)
    // value 0 is the root and pointing to -1, which means that it has no proper ancestor.
    int PP[MAX_NODES + 1] = {-1, 0, 1, 1, 2, 2, 5, 5, 5, 3, 3};
    depthPP(PP, MAX_NODES); // 10 is the number of nodes currently in PP starting from indx 2

    // 1st tree representation (Completed)

    Tree T;
    initTree(&T, 1);
    addChild(&T, 1, 2);
    addChild(&T, 1, 3);
    addChild(&T, 2, 4);
    addChild(&T, 2, 5);
    addChild(&T, 3, 9);
    addChild(&T, 3, 10);
    addChild(&T, 5, 6);
    addChild(&T, 5, 7);
    addChild(&T, 5, 8);

    printChildren(T, 1);
    printChildren(T, 2);
    printChildren(T, 3);
    printChildren(T, 5);

    printf("DepthLL (Root): %d\n\n", depthLL(T, 1));

    // 2nd tree representation (Completed)

    BT BT = {{1, 2, 3, 4, 5, 6, 7 ,8, 9, 10}, 9};
    depthBT(BT);

    return 0;
}

void depthPP(int PP[], int nodeSize){
    int max_depth = 0;
    // Iterates all possible paths
    for(int i = 1; i <= nodeSize; i++){
        int current = i, depth = 0;
        while(PP[current] != 0){
            current = PP[current];
            depth++;
        }
        // Stores the maximum height from root to leaf
        if(depth > max_depth) max_depth = depth; 
    }
    printf("DepthPP (Root): %d\n\n", max_depth);
}

void initTree(Tree* T, int rootIndex){
    T->root = rootIndex;
    for(int i = 0; i <= MAX_NODES; i++){
        T->header[i] = NULL;
    }
}

ListElement* createNode(int nodeIndex){
    ListElement* newNode = (ListElement*)malloc(sizeof(struct ListElement));

    if(newNode != NULL && nodeIndex <= MAX_NODES){
        newNode->nodeIndex = nodeIndex;
        newNode->next = NULL;
    }else{
        printf("Creating new node failed (Malloc/NodeIndex ([%d] > %D)?)\n", nodeIndex, MAX_NODES);
    }

    return (newNode != NULL && nodeIndex <= MAX_NODES) ? newNode: NULL;
}

void addChild(Tree* T, int parentIndex, int childIndex){
    ListElement* newNode = createNode(childIndex);

    if(newNode == NULL){
        printf("Add child unsuccessful!\n\n");
        return;
    }

    if(T->header[parentIndex] == NULL){
        T->header[parentIndex] = newNode;
    }else{
        ListElement* current = T->header[parentIndex];
        for(; current->next != NULL; current = current->next){}
        current->next = newNode;
    }
}

void printChildren(Tree T, int parentIndex) {
    printf("Children of Node %d: ", parentIndex);
    ListElement* current = T.header[parentIndex]; // Access Leftmost Child
    
    if (current != NULL) {
        for(; current != NULL; current = current->next) printf("%d -> ", current->nodeIndex);
        printf("NULL\n");
    } else{
        printf("None\n");
    }
}

int depthLL(Tree T, int rootIndex){
    if(T.header[rootIndex] == NULL){
        return 0;
    }

    int max_depth = 0;
    ListElement* current = T.header[rootIndex];

    for(; current != NULL; current = current->next){
        int h = depthLL(T, current->nodeIndex);
        if(h > max_depth){
            max_depth = h;
        }
    }
    return max_depth + 1;
}

void depthBT(BT BT){
    int max_depth = 0;
    int trav = BT.lastIndex;
    for(; trav != 0; trav = (trav-1)/2) max_depth++;

    printf("DepthBT (Root): %d", max_depth);
}