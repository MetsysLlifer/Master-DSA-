#include "util.h"


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
