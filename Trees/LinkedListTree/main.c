#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

// A. The Linked List Element (ListElement)
// Represents the horizontal boxes in Fig 3.12
typedef struct ListElement {
    int nodeIndex;              // The integer ID of the child
    struct ListElement* next;   // The pointer to the next sibling
} ListElement;

// B. The Tree Structure (Tree)
// Represents the vertical column in Fig 3.12
typedef struct {
    ListElement* header[MAX_NODES]; // Array of pointers to the first child of each node
    int root;                       // Stores the root node index
} Tree;


void initTree(Tree* T, int rootIndex);
ListElement* createNode(int nodeIndex);
void addChild(Tree* T, int parentIndex, int childIndex);

int getLeftmostChild(Tree T, int n);
void printChildren(Tree T, int parentIndex);


int main() {
    Tree T;
    
    // 1. Initialize Tree with root at index 1
    initTree(&T, 1);

    // 2. Build the Tree described in the prompt
    // Node 1 has children 2 and 3
    addChild(&T, 1, 2); // Arrow from 1 to 2 (Leftmost)
    addChild(&T, 1, 3); // Arrow from 2 to 3 (Right Sibling)

    // Node 2 has child 4
    addChild(&T, 2, 4); // Arrow from 2's header to 4

    // 3. Display results
    printChildren(T, 1); // Should print: 2 -> 3 -> NULL
    printChildren(T, 2); // Should print: 4 -> NULL
    printChildren(T, 3); // Should print: None

    // Check Leftmost Child operation
    printf("Leftmost child of 1: %d\n", getLeftmostChild(T, 1));

    return 0;
}


// Initialization: Sets all headers to NULL (empty boxes)
void initTree(Tree* T, int rootIndex) {
    T->root = rootIndex;
    for (int i = 0; i < MAX_NODES; i++) {
        T->header[i] = NULL;
    }
}

// Function to create a new ListElement node
ListElement* createNode(int nodeIndex) {
    ListElement* newNode = (ListElement*)malloc(sizeof(ListElement));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->nodeIndex = nodeIndex;
    newNode->next = NULL;
    return newNode;
}

// Adding a Child (addChild)
// Links parent to child, maintaining the list order
void addChild(Tree* T, int parentIndex, int childIndex) {
    // 1. Create the Element
    ListElement* newNode = createNode(childIndex);

    // 2. Link to Parent
    // If the parent has no children yet, this becomes the Leftmost Child
    if (T->header[parentIndex] == NULL) {
        T->header[parentIndex] = newNode;
    } else {
        // 3. Find the End & Link Sibling
        // Traverse to the end of the list to add as the Right Sibling of the last child
        ListElement* current = T->header[parentIndex];
        for(; current->next != NULL; current = current->next){}
        current->next = newNode;
    }
}

// Operation: LEFTMOST_CHILD(n, T)
// Returns the index of the first child, or -1 if leaf
int getLeftmostChild(Tree T, int n) {
    if (T.header[n] != NULL) {
        return T.header[n]->nodeIndex;
    }
    return -1; // No children
}

// Operation: RIGHT_SIBLING(n, T)
// Requires searching the parent's list to find n, then returning n->next
// Note: In this specific implementation, finding a sibling often requires knowing the parent.
// For simplicity here, we search the specific list if we know the parent, or simpler logic if we have the node pointer.
// Below is a general helper to print children which demonstrates traversing siblings.
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