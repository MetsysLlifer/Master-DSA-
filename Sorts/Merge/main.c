#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/* ----- MERGE SORT -----
1. Divide: The array is recursively split into two halves until each subarray has only one element.
2. Sort and Merge: Single-element subarrays are then merged back together in sorted order.
3. Final Merge: The two final sorted halves are merged to produce the complete sorted array.

Reference: https://www.youtube.com/watch?v=5Z9dn2WTg9o&list=PLclGofX5Jcz4kulV0A8XPeQrU6AnJaT51&index=2
*/

void mergeSort(int* arr, int size);
void populateArray(int* arr, int size);
void displayArray(int* arr, int size);

int main(){
    int arr[MAX];
    populateArray(arr, MAX);
    mergeSort(arr, MAX);

    displayArray(arr, MAX);
    return 0;
}


void mergeSort(int* arr, int size){
    // ------------------------- DIVIDE ------------------------- //
    if(size > 1){
        // range is the array size for right partition
        int rangeA = size/2;
        int rangeB = size - rangeA; // prioritize right partition

        int arrA[rangeA]; // left partition
        int arrB[rangeB]; // right partition

        // Left Partition
        for(int trav = 0; trav < rangeA; trav++){
            arrA[trav] = arr[trav];
        }

        // Right Partition
        for(int trav = 0; trav < rangeB; trav++){
            arrB[trav] = arr[rangeA+trav];
        }
    
        mergeSort(arrA, rangeA);
        mergeSort(arrB, rangeB);

    // ------------------------------------------------------------- //

    // ------------------------- SORT AND MERGE ------------------------- //
        int indexA = 0;
        int indexB = 0;

        for(int trav = 0; trav < size; trav++){
            
            // We exhausted arrA, so we must take from arrB
            if(indexA == rangeA) {
                arr[trav] = arrB[indexB++];
            }
            // We exhausted arrB, so we must take from arrA
            else if(indexB == rangeB) {
                arr[trav] = arrA[indexA++];
            }
            // Both have items, perform standard comparison
            else if(arrA[indexA] < arrB[indexB]) {
                arr[trav] = arrA[indexA++];
            }
            else {
                arr[trav] = arrB[indexB++];
            }
        }
    // ------------------------------------------------------------------ //
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