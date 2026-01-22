#include <stdio.h>
#include <stdlib.h>
#define MAX 10

/* ----- INSERTION SORT
1. Take the first value from the unsorted part of the array.
2. Move the value into the correct place in the sorted part of the array.
3. Go through the unsorted part of the array again as many times as there are values.
*/

void populateArray(int* arr, int size);
void displayArray(int* arr, int size);
void insertionSort(int* arr, int size);

int main(){
    int arr[MAX];
    populateArray(arr, MAX);

    insertionSort(arr, MAX);

    displayArray(arr, MAX);
    return 0;
}


void insertionSort(int* arr, int size){
    int length = size-1;
    for(int travA = 0; travA < length; travA++){
        if(arr[travA+1] < arr[travA]){
            for(int travB = travA+1; travB > 0; travB--){
                if(arr[travB] < arr[travB-1]){
                    int temp = arr[travB-1];
                    arr[travB-1] = arr[travB];
                    arr[travB] = temp;
                }
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

