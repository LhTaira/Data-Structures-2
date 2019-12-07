#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define bool char
#define true 1
#define false 0
#define INFINITY 9999

typedef struct Graph {
    int nVerticves;
    int ** matrix;
} Graph;

void link(Graph * graph, int source, int destination, int type, int cost) {
    graph->matrix[source][destination] = cost;
    
    if(type == 2) {
        link(graph, destination, source, 1, cost);
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