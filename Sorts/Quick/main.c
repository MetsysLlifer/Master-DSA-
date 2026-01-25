#include <stdio.h>
#include <stdlib.h>
#define MAX 5


void quickSort(int* arr, int firstPos, int lastPos);
void populateArray(int* arr, int size);
void displayArray(int* arr, int size);


int main(){
    int arr[MAX];
    populateArray(arr, MAX);
    quickSort(arr, 0, MAX);

    displayArray(arr, MAX);
    return 0;
}

void quickSort(int* arr, int firstPos, int lastPos) {
    // 1. Base Case: If the range has 0 or 1 element, it's already sorted.
    if (firstPos >= lastPos) {
        return;
    }

    // --- Partitioning Logic (Lomuto Scheme) ---
    // We choose the last element as the pivot
    int pivotValue = arr[lastPos]; 
    
    // 'pointA' tracks the tail of the "smaller than pivot" section
    int pointA = firstPos - 1; 

    for (int trav = firstPos; trav < lastPos; trav++) {
        // If current element is smaller than or equal to pivot
        if (arr[trav] <= pivotValue) {
            pointA++; 
            
            // Swap current element to the "smaller" section
            int temp = arr[pointA];
            arr[pointA] = arr[trav];
            arr[trav] = temp;
        }
    }

    // Place the pivot in its correct sorted position
    // (Right after the last smaller element)
    int partitionIndex = pointA + 1;
    int temp = arr[partitionIndex];
    arr[partitionIndex] = arr[lastPos];
    arr[lastPos] = temp;
    // -------------------------------------------

    // 2. Recursive Calls
    // Sort the Left Subarray (elements smaller than pivot)
    quickSort(arr, firstPos, partitionIndex - 1);

    // Sort the Right Subarray (elements larger than pivot)
    quickSort(arr, partitionIndex + 1, lastPos);
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

