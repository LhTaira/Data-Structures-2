#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node * next;
} Node;

typedef struct Array {
    int julius;
    int * array;
    int arraySize;
} Array;

int checkVizinhos(Array * array, int * array2, int size) {
    if(array2 == NULL) {
        return 0;
    }
    for(int i = 0; i < size; i++) {
        if(array[array2[i]].julius) {
            return 1;
        }
    }
    return 0;
}

int checkForJulius(Array * array, int lugar) {
    if(array[lugar].julius == 1) {
        return 1;
    }
    if(checkVizinhos(array, array[lugar].array, array[lugar].arraySize)) {
        return 1;
    }
    return 0;
}

int main() {
    Node * lista = NULL;
    Array * array;
    int nLugares, nJulius, nMalvo, nVizinhos, vizinho;

    scanf("%d", &nLugares);
    scanf("%d", &nJulius);
    scanf("%d", &nMalvo);

    array = malloc(nLugares * sizeof(Array));

    for(int i = 0; i < nLugares; i++) {
        array[i].julius = 0;
        scanf("%d", &nVizinhos);
        array[i].array = malloc(nVizinhos * sizeof(int));
        array[i].arraySize = nVizinhos;
        for(int j = 0; j < nVizinhos; j++) {
            scanf("%d", &vizinho);
            array[i].array[j] = vizinho;
        }
    }

    for(int i = 0; i < nJulius; i++) {
        scanf("%d", &vizinho);
        array[vizinho].julius = 1;
    }

    for(int i = 0; i < nMalvo; i++) {
        scanf("%d", &vizinho);
        if(checkForJulius(array, vizinho)) {
            printf("Eu vou estar la\n");
        } else {
            printf("Nao vou estar la\n");
        }
    }
}