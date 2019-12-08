#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

typedef struct List {
    struct List * next;
    int number;
} List;

typedef struct Graph {
    List * list;
    List * listEnd;
    char name[31];
} Graph;

void createHeap(Graph * graph, int number) {
    graph->list = (List *) malloc(sizeof(List));
    graph->list->next = NULL;
    graph->list->number = number;
    graph->listEnd = graph->list;
}

void push(Graph * graph, int number) {
    List * newNode;

    if(graph->list == NULL) {
        return createHeap(graph, number);
    }

    newNode = (List *) malloc(sizeof(List));
    newNode->next = NULL;
    newNode->number = number;

    graph->listEnd->next = newNode;
    graph->listEnd = newNode;
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
    int * counter = (int *) malloc(sizeof(int)), maior, countSize, ** preMatrix;
    Graph * graph;
    int nNomes, nCadeias;
    char predador[31], presa[31];

    scanf("%d %d", &nNomes, &nCadeias);

    while(nNomes != 0) {
        map<string, int> cadeia;
        preMatrix = (int **) malloc(nNomes * sizeof(int *));
        graph = (Graph *) malloc(nNomes * sizeof(Graph));        

        for(int i = 0; i < nNomes; i++) {
            preMatrix[i] =(int *) malloc(nNomes * sizeof(int));
            graph[i].list = NULL;
        }

        for(int i = 0; i < nNomes; i++) {
            scanf("%s", graph[i].name);
            cadeia[graph[i].name] = i;
        }

        for(int i = 0; i < nCadeias; i++) {
            scanf("%s %s", presa, predador);
            push(&graph[cadeia[predador]], cadeia[presa]);
        }

        for(int i = 0; i < nNomes; i++) {
            for(int j = 0; j < nNomes; j++) {
                preMatrix[i][j] = -1;
            }
            for(int j = 0; j < nNomes; j++) {
                *counter = 0;
                dfsR(graph, i, j, preMatrix[i], counter, nNomes);
            }
        }

        maior = 0;
        for(int i = 0; i < nNomes; i++) {
            countSize = 0;
            for(int j = 0; j < nNomes; j++) {
                if(preMatrix[j][i] != -1) {
                    countSize++;
                }
            }
            if(countSize > maior) {
                maior = countSize;
            }
        }

        printf("%d\n", maior);
        scanf("%d %d", &nNomes, &nCadeias);
    }
}