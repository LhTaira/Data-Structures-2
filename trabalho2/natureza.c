#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heap {
    struct Heap * next;
    int number;
} Heap;

typedef struct Graph {
    Heap * heap;
    Heap * heapEnd;
    char name[31];
} Graph;

typedef struct Edge {
    int n1, n2;
} Edge;

Edge EDGE(int, int);

void createHeap(Graph * graph, int number) {
    graph->heap = malloc(sizeof(Heap));
    graph->heap->next = NULL;
    graph->heap->number = number;
    graph->heapEnd = graph->heap;
}

void push(Graph * graph, int number) {
    Heap * newNode;

    if(graph->heap == NULL) {
        return createHeap(graph, number);
    }

    newNode = malloc(sizeof(Heap));
    newNode->next = NULL;
    newNode->number = number;

    graph->heapEnd->next = newNode;
    graph->heapEnd = newNode;
} 

void makeLink(Graph * graph, char * predador, char * presa) {
    int predadorIndex = 0, presaIndex = 0;

    while(strcmp(graph[predadorIndex].name, predador) != 0) {
        predadorIndex++;
    }

    while(strcmp(graph[presaIndex].name, presa) != 0) {
        presaIndex++;
    }

    push(&graph[predadorIndex], presaIndex);
}

void printGraph(Graph * graph, int nNomes) {
    Heap * aux;

    for(int i = 0; i < nNomes; i++) {
        printf("%s", graph[i].name);

        aux = graph[i].heap;
        while(aux != NULL) {
            printf(" %d", aux->number);
            aux = aux->next;
        }
        printf("\n");
    }
}

void freeEverything(Graph * graph, int nNomes) {
    Heap * aux, * aux2;
    for(int i = 0; i < nNomes; i++) {
        aux = graph[i].heap;
        while(aux != NULL) {
            aux2 = aux->next;
            free(aux);
            aux = aux2;
        }
    }
    free(graph);
}

void dfsR(Graph graph, Edge edge, int * pre, int counter;) {
    int v = edge.n1;
    pre[v] = counter++;

    for(int t = 0; t < graph)
}

int main() {
    Graph * graph;
    int nNomes, nCadeias;
    char predador[31], presa[31];

    scanf("%d %d", &nNomes, &nCadeias);

    while(nNomes != 0 && nCadeias != 0) {

        graph = malloc(nNomes * sizeof(Graph));
        for(int i = 0; i < nNomes; i++) {
            graph[i].heap == NULL;
        }

        for(int i = 0; i < nNomes; i++) {
            scanf("%s", graph[i].name);
        }

        for(int i = 0; i < nCadeias; i++) {
            scanf("%s %s", presa, predador);
            makeLink(graph, predador, presa);
        }

        // printGraph(graph, nNomes);

        freeEverything(graph, nNomes);

        scanf("%d %d", &nNomes, &nCadeias);
    }
}