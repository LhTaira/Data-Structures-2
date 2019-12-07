#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 99999

typedef struct Graph {
    int nVerticves;
    int ** matrix;
} Graph;

void link(Graph * graph, int source, int destination, int type) {
    graph->matrix[source][destination] = 1;
    
    if(type == 2) {
        link(graph, destination, source, 1);
    }
}

int ** floydWarshall(Graph * graph){
    // int ** solution = malloc(graph->nVerticves * sizeof(int *));
    int ** solution = graph->matrix;
    // for(int i = 0; i < graph->nVerticves; i++) {
    //     solution[i] = malloc(graph->nVerticves * sizeof(int));
    // }

    // for(int i = 0; i < graph->nVerticves; i++) {
    //     for(int j = 0; j < graph->nVerticves; j++) {
    //         solution[i][j] = graph->matrix[i][j];
    //     }
    // }

    for(int k = 0; k < graph->nVerticves; k++) {
        for(int i = 0; i < graph->nVerticves; i++) {
            for(int j = 0; j < graph->nVerticves; j++) {
                if(solution[i][k] + solution[k][j] < solution[i][j]) {
                    solution[i][j] = solution[i][k] + solution[k][j];
                }
            }
        }
    }

    return solution;
}

int main() {
    Graph * graph = malloc(sizeof(Graph));
    int ** solution, saida, nVerticves, nArestas, destination, type, source;
    
    scanf("%d", &nVerticves);


    while(nVerticves != 0) {
        graph->matrix = malloc(nVerticves * sizeof(int *));
        scanf("%d", &nArestas);
        saida = 1;
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
            scanf("%d %d %d", &source, &destination, &type);
            link(graph, source - 1, destination - 1, type);
        }

        solution = floydWarshall(graph);

        for(int i = 0; i < graph->nVerticves; i++) {
            for(int j = 0; j < graph->nVerticves; j++) {
                if(solution[i][j] == INF) {
                    saida = 0;
                    break;
                } 
            }
        }

        printf("%d\n", saida);

        // for(int i = 0; i < nVerticves; i++) {
        //     free(graph->matrix[i]);
        // }

        scanf("%d", &nVerticves);
    }


    return 0;    
}