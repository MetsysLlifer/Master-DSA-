#include <stdio.h>
#include <stdlib.h>
#define MAX 5


typedef struct{
    int** adjMatrix;
    int numVertices;
}Graph;

void initVisited(int*);
Graph* createGraph(int);
void addEdge(Graph*, int, int);
void display(Graph);
void DFS(Graph, int, int*);


int main(){
    int visited[MAX];
    initVisited(visited);
    Graph* G = createGraph(MAX);
    
    
    
    // Debugging purpose
    // G->adjMatrix[0][0] = 1;
    // G->adjMatrix[1][1] = 1;
    // G->adjMatrix[2][2] = 1;
    // G->adjMatrix[3][3] = 1;
    // G->adjMatrix[4][4] = 1;
    
    addEdge(G, 0, 1);
    addEdge(G, 0, 4);
    addEdge(G, 1, 2);
    addEdge(G, 1, 3);
    addEdge(G, 1, 4);
    addEdge(G, 2, 3);
    addEdge(G, 3, 4);
    
    display(*G);
    DFS(*G, 0, visited);
    return 0;
}

void initVisited(int* v){
    for(int trav = 0; trav < MAX; trav++){
        v[trav] = 0;
    }
}

Graph* createGraph(int vertices){
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    
    graph->adjMatrix = (int**)malloc(sizeof(int*) * vertices);
    
    for(int trav = 0; trav < vertices; trav++){
        graph->adjMatrix[trav] = (int*)malloc(sizeof(int) * vertices);
        for(int jtrav = 0; jtrav < vertices; jtrav++){
            graph->adjMatrix[trav][jtrav] = 0;
        }
    }
    return graph;
}

void display(Graph G){
    for(int i = 0; i < G.numVertices; i++){
        for(int j = 0; j < G.numVertices; j++){
            printf("%d%s", G.adjMatrix[i][j], j+1==G.numVertices?"\n":" ");
        }
    }
    printf("\n\n");
}


void addEdge(Graph* G, int src, int dest){
    G->adjMatrix[src][dest] = 1;
    G->adjMatrix[dest][src] = 1;
}


void DFS(Graph G, int vertex, int* visited){
    visited[vertex] = 1;
    printf("%d", vertex);
    for(int trav = 0; trav < G.numVertices; trav++){
        if(G.adjMatrix[vertex][trav] == 1){
            if(visited[trav] == 0) DFS(G, trav, visited);
        }
    }
}