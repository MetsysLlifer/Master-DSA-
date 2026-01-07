#include "util.h"

// Chapter 2.4 QUEUE
// Circular Array of Queues

/*
The functions are slightly different compared to what the book described
*/  

// Page 58-9


int main(){
    QueueType Q;
    makeNull(&Q);

    enqueue(&Q, 'A');
    enqueue(&Q, 'B');
    dequeue(&Q);
    enqueue(&Q, 'C');
    enqueue(&Q, 'A');
    enqueue(&Q, 'B');
    dequeue(&Q);
    enqueue(&Q, 'C');
    //Expected output: C <- A <- B <- C 

    checkNodes(Q);

    return 0;
}
