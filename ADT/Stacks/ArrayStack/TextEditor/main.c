#include "util.h"

// Chapter 2.3 STACKS
// Array of Stacks
// Example 2.2 Text Editor
// Fig 2.16 Program to carry out effects of erase and kill characters

// Page 53-54


int main(){
    char input[MAX];
    Stack S;
    makeNull(&S);

    printf("SIMPLE TEXT EDITOR:\n'#' removes previous character and '@' clears everything\n");
    printf("Enter text: ");
    scanf("%s", input);
    
    storeText(&S, input);

    printf("%s\n", input);
    printf(empty(S)? "Stack is Empty\n": "Stack is not Empty\n");
    printf("%c\n", top(S));

    return 0;
}
