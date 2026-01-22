#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/* ----- SELECTION SORT -----
1. Go through the array to find the lowest value.
2. Move the lowest value to the front of the unsorted part of the array.
3. Go through the array again as many times as there are values in the array.

Reference: https://www.w3schools.com/dsa/dsa_algo_selectionsort.php
*/

void selectionSort(int* arr, int size);
void populateArray(int* arr, int size);
void displayArray(int* arr, int size);

int main(){
    int arr[MAX];
    populateArray(arr, MAX);
    selectionSort(arr, MAX);

    displayArray(arr, MAX);
    return 0;
}


void selectionSort(int* arr, int size){
    int indexPointer;
    int range = size-1;
    for(int travA = 0; travA < range; travA++){
        indexPointer = travA;
        for(int travB = travA+1; travB < size; travB++){
            // Get the smallest value and store the index in the variable (indexPointer)
            if(arr[travB] < arr[indexPointer]) indexPointer = travB;
        }
        if(indexPointer != travA){
            int temp = arr[travA];
            arr[travA] = arr[indexPointer];
            arr[indexPointer] = temp;
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

