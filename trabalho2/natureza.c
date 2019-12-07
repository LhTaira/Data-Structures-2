#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define vertex int

// typedef struct node *link;
// struct node { 
//    vertex w; 
//    link next; 
// };

typedef struct List {
    struct List * next;
    int number;
} List;

typedef struct Graph {
    List * list;
    List * heapEnd;
    char name[31];
} Graph;

// typedef struct Edge {
//     int n1, n2;
// } Edge;

// Edge EDGE(int a, int b) {
//     Edge c;
//     c.n1 = a;
//     c.n2 = b;
//     return c;
// }

void createHeap(Graph * graph, int number) {
    graph->list = malloc(sizeof(List));
    graph->list->next = NULL;
    graph->list->number = number;
    graph->heapEnd = graph->list;
}

void push(Graph * graph, int number) {
    List * newNode;

    if(graph->list == NULL) {
        return createHeap(graph, number);
    }

    newNode = malloc(sizeof(List));
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
    List * aux;

    for(int i = 0; i < nNomes; i++) {
        printf("%s", graph[i].name);

        aux = graph[i].list;
        while(aux != NULL) {
            printf(" %d", aux->number);
            aux = aux->next;
        }
        printf("\n");
    }
}

void freeEverything(Graph * graph, int nNomes) {
    List * aux, * aux2;
    for(int i = 0; i < nNomes; i++) {
        aux = graph[i].list;
        while(aux != NULL) {
            aux2 = aux->next;
            free(aux);
            aux = aux2;
        }
    }
    free(graph);
}

int getItem(Graph graph, int index) {
    while(graph.list != NULL) {
        if(graph.list->number == index) {
            return 1;
        }
        graph.list = graph.list->next;
    }
    return -1;
}

void dfsR(Graph * graph, int source, int destination, int * pre, int * counter, int nVertices) {
    pre[source] = (*counter)++;
    for(int t = 0; t < nVertices; t++) {
        if(getItem(graph[source], t) != -1) {
            if(pre[t] == -1) {
                dfsR(graph, t, destination, pre, counter, nVertices);
            }
        }
    }
}

int main() {
    int * pre, * counter = malloc(sizeof(int)), maior;

    Graph * graph;
    int nNomes, nCadeias;
    char predador[31], presa[31];

    scanf("%d %d", &nNomes, &nCadeias);

    while(nNomes != 0 && nCadeias != 0) {
        
        pre = malloc(nNomes * sizeof(int));
        graph = malloc(nNomes * sizeof(Graph));
        maior = -1;

        for(int i = 0; i < nNomes; i++) {
            graph[i].list == NULL;
        }

        for(int i = 0; i < nNomes; i++) {
            scanf("%s", graph[i].name);
        }

        for(int i = 0; i < nCadeias; i++) {
            scanf("%s %s", presa, predador);
            makeLink(graph, predador, presa);
        }

        for(int i = 0; i < nNomes; i++) {
            for(int j = 0; j < nNomes; j++) {
                pre[j] = -1;
            }
            for(int j = 0; j < nNomes; j++) {
                *counter = 0;
                dfsR(graph, i, j, pre, counter, nNomes);
            }
            for(int j = 0; j < nNomes; j++) {
                printf("%d ", pre[j]);
                if(pre[j] > maior && j != i) {
                    maior = pre[j];
                }
            }
            printf("\n");
        }

        printf("%d\n", maior + 1);

        // freeEverything(graph, nNomes);
        free(pre);
        // scanf("%c");
        scanf("%d %d", &nNomes, &nCadeias);
    }
}