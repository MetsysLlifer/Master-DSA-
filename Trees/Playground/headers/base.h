#define MaxName 25
#define MaxSize 10
// #define EmptyVH -1
// #define Empty (int)(pow(2, 32)-1)
#define Empty -1

typedef int index, Tree, element;

typedef struct{
    index node;
    index next;
} Slot;

typedef struct{
    Slot slots[MaxSize];
    index avail;
} VirtualHeap;

typedef struct{
    char name[MaxName];
    index next;
} Node;

typedef struct{
    Node nodes[MaxSize];
} Nodespace;