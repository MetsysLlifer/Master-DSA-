#include <stdio.h>
#include <stdlib.h>
#define MAX 15
#define EMPTY -1

typedef struct{
    int* array;
    int size;
    int capacity;
} MaxHeap;

int parent(int);
int leftChild(int);
int rightChild(int);

void initMH(MaxHeap*);
void swap(int*, int*);
void insert(MaxHeap*, int);

void printHeap(MaxHeap);
void preOrder(MaxHeap, int);

int extractMax(MaxHeap*);

int main(){
    MaxHeap MH;
    initMH(&MH);
    
    insert(&MH, 10);
    insert(&MH, 20);
    insert(&MH, 15);
    insert(&MH, 50);
    
    printf("MaxHeap: ");
    printHeap(MH);
    printf("\npreOrder: " );
    preOrder(MH, 0);
    
    
    printf("\n\nFirst Max: %d", extractMax(&MH));
    printf("\nSecond Max: %d", extractMax(&MH));
    printf("\nThird Max: %d", extractMax(&MH));
    printf("\nFourth Max: %d", extractMax(&MH));
    printf("\npreOrder: " );
    preOrder(MH, 0);
    return 0;
}


int parent(int i){
    return (i-1)/2;
}

int leftChild(int i){
    return i*2+1;
}

int rightChild(int i){
    return i*2+2;
}


void initMH(MaxHeap* MH){
    MH->array = (int*)malloc(sizeof(int) * MAX);
    MH->size = EMPTY;
    MH->capacity = MAX;
}

void swap(int* A, int* B){
    int temp = *A;
    *A = *B;
    *B = temp;
    
}

void insert(MaxHeap* MH, int value){
    if(MH->size+1 == MH->capacity) return;

    MH->array[++MH->size] = value;
    int trav = MH->size;
    while(trav > 0 && MH->array[trav] > MH->array[parent(trav)]){
        swap(&MH->array[trav], &MH->array[parent(trav)]);
        trav = parent(trav);
    }
}

void printHeap(MaxHeap MH){
    for(int trav = 0; trav <= MH.size; trav++){
        printf("%d ", MH.array[trav]);
    }
}

void preOrder(MaxHeap MH, int idx){
    if(idx <= MH.size){
        printf("%d ", MH.array[idx]);
        if(leftChild(idx) <= MH.size) preOrder(MH, leftChild(idx));
        if(rightChild(idx) <= MH.size) preOrder(MH, rightChild(idx));
    }
}


int extractMax(MaxHeap* MH){
    if(MH->size == EMPTY) return -1;
    
    int result = MH->array[0];
    MH->array[0] = MH->array[MH->size--];
    
    int node = 0;
    while(1){
        int current_largest = node;
        int lc = leftChild(node);
        int rc = rightChild(node);
        
        if(lc <= MH->size && MH->array[lc] > MH->array[current_largest]){
            current_largest = lc;
        }
        if(rc <= MH->size && MH->array[rc] > MH->array[current_largest]){
            current_largest = rc;
        }
        
        if(node != current_largest){
            swap(&MH->array[node], &MH->array[current_largest]);
            node = current_largest;
        }else{
            break;
        }
    }
    return result;
}



