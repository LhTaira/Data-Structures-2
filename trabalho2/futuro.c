#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define bool char
#define true 1
#define false 0
#define INFINITY MAX_INT

typedef struct Graph {
    int nVerticves;
    int ** matrix;
} Graph;

void link(Graph * graph, int source, int destination, int type, int cost) {
    graph->matrix[source][destination] = cost;
    
    if(type == 2) {
        link(graph, destination, source, 1);
    }
}

void dijkstra(Graph * graph, int source, int * pais, int * distancia) {
    bool tree[1000];
    for (int v = 0; v < graph->nVerticves; ++v) {
        pais[v] = -1;
        tree[v] = false;
        distancia[v] = INFINITY;
    }

    pais[source] = source;
    tree[source] = true;
    distancia[source] = 0;

    for (link a = graph->adj[source]; a != NULL; a = a->next) {        
        pais[a->w] = source;
        distancia[a->w] = a->c;
    }

    while (true) {
        int min = INFINITY;
        int y;
        for (int z = 0; z < graph->nVerticves; ++z) {
            if (!tree[z]) {
            continue;
            }
            if (distancia[z] < min) {
            min = distancia[z], y = z;
            }
        }
        if (min == INFINITY) {
            break;
        }
        tree[y] = true;
        
        for (link a = graph->adj[y]; a != NULL; a = a->next) {
            if (tree[a->w]) {
                continue;
            }
            if (distancia[y] + a->c < distancia[a->w]) {
                distancia[a->w] = distancia[y] + a->c;
                pais[a->w] = y;
            }
        }
    }
}

int main() {
    Graph * graph = malloc(sizeof(Graph));

    while(scanf("%d %d", &nVerticves, &nArestas) == 2) {
        graph->matrix = malloc(nVerticves * sizeof(int *));
        graph->nVerticves = nVerticves;

        for(int i = 0; i < nVerticves; i++) {
            graph->matrix[i] = malloc(nVerticves * sizeof(int));
        }

        for(int i = 0; i < nVerticves; i++) {
            for(int j = 0; j < nVerticves; j++) {
                graph->matrix[i][j] = INF;
            }
        }

        for(int i = 0; i < nArestas; i++) {
            scanf("%d %d %d", &source, &destination, &cost);
            link(graph, source - 1, destination - 1, 2, cost);
        }

    }

}