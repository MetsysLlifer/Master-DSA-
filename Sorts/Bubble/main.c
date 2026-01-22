#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// Bubble Sort pushes highest value in the array to the right every iteration.
// Once the highest value pushed to the right most index, decrement the size by 1 and loop again
// until it's sorted.

void bubbleSort(int* arr, int size);
void populateArray(int* arr, int size);
void displayArray(int* arr, int size);

int main(){
    int arr[MAX];
    populateArray(arr, MAX);
    bubbleSort(arr, MAX);

    displayArray(arr, MAX);
    return 0;
}


void bubbleSort(int* arr, int size){
    for(int travA = 0; travA < size-1; travA++){
        for(int travB = 0; travB < size-travA; travB++){
            if(arr[travB] > arr[travB+1]){
                int temp = arr[travB];
                arr[travB] = arr[travB+1];
                arr[travB+1] = temp;
            }
        }
    }
}

void populateArray(int* arr, int size){
    for(int trav = 0; trav < size; trav++){
        arr[trav] = rand() % size + 1;
    }
}


void displayArray(int* arr, int size){
    for(int trav = 0; trav < size; trav++){
        printf("[%d]: %d\n", trav, arr[trav]);
    }
}
