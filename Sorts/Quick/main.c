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

// Incomplete
void quickSort(int* arr, int firstPos, int lastPos){
int pivotIndex = lastPos - 1;
    int pivotValue = arr[pivotIndex]; // Store value for clarity
    
    // Standard Lomuto: Start 'pointA' (often called 'i') behind the start
    int pointA = firstPos - 1; 

    for(int trav = firstPos; trav < lastPos; trav++){
        // If current element is smaller than or equal to pivot
        if(arr[trav] <= pivotValue){
            pointA++; // Move boundary of "smaller elements" forward
            
            // Swap current element to the "smaller" section
            int temp = arr[pointA];
            arr[pointA] = arr[trav];
            arr[trav] = temp;
        }
    }

    // Swap the pivot into its correct slot (right after the smaller elements)
    int temp = arr[pointA + 1];
    arr[pointA + 1] = arr[pivotIndex];
    arr[pivotIndex] = temp;
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

