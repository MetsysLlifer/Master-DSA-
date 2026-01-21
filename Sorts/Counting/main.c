#include <stdio.h>
#define MAX 6

// --- This works very best when the range of number each value could have is very small --- //
/*
Here are the steps of doing Counting Sort
    1. Count Occurences: count the number of occurrences for each unique element in the array
    2. Calculate Cummulaative Sum: add counts cumulatively from left to right
    3. Shift for Start Indexes: Shift the cumulative array right by one to get starting positions.
    4. Populate Sorted Array: Place elements into their sorted positions in a new array, incrementing their start index as you go.

Reference: https://www.youtube.com/watch?v=OKd534EWcdk
*/

void initArray(int* arr, int size); // array and size
void getMaxValue(int* arr, int* size); // array and size pointer (updates the value of size)
void displayArray(int* arr, int size);


int main(){
    int arr[MAX] = {1, 0, 3, 1, 3, 1};
    printf("-----Unsorted Array-----\n");
    displayArray(arr, MAX);
    
    // -----  Count Occurences ----- //
    int size = 0;
    // We will assume that the array has value and get the largest value
    getMaxValue(arr, &size);

    int range = size + 1; // +1 to include the number itself (ex, size = 3, range[3+1] = 0, 1, 2, 3)
    int numOccur[range];
    initArray(numOccur, range);

    for(int trav = 0; trav < MAX; trav++){
        numOccur[arr[trav]]++;
    }
    // ------------------------------//

    // ----- Cumulative Sum ----- //
    for(int trav = 1; trav < range; trav++){
        numOccur[trav] += numOccur[trav-1];
    }
    // ------------------------------//

    // ----- Shift for Start Indexes ----- //
    // exclude the 0 index from the loop to set as 0
    for(int trav = size; trav > 0; trav--){
        numOccur[trav] = numOccur[trav-1];
    }
    numOccur[0] = 0;
    // ------------------------------//

    // ----- Populate Sorted Array ----- //
    int sortedArray[MAX];
    initArray(sortedArray, MAX);

    for(int trav = 0; trav < MAX; trav++){
        sortedArray[numOccur[arr[trav]]++] = arr[trav];
    }
    // ------------------------------//

    printf("-----Sorted Array-----\n");
    displayArray(sortedArray, MAX);
    return 0;
}

void initArray(int* arr, int size){
    for(int trav = 0; trav < size; trav++){
        arr[trav] = 0;
    }
}

void getMaxValue(int* arr, int* size){
    for(int i = 0; i < MAX; i++){
        if(arr[i] > *size) *size = arr[i];
    }
}

void displayArray(int* arr, int size){
    for(int trav = 0; trav < size; trav++){
        printf("[%d]: %d\n", trav, arr[trav]);
    }
}