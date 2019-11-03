#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node * next;
} Node;

typedef struct ArrayDeListas {
    int julius;
    Node * lista;
} ArrayDeListas;

Node * createLista(int value) {
    Node * newLista = malloc(sizeof(Node));
    newLista->next = NULL;
    newLista->value = value;
    return newLista;
}

Node * addLista(Node * lista, int value) {
    if(lista == NULL) {
        return createLista(value);
    }
    lista->next = addLista(lista->next, value);
    return lista;
}

int checkVizinhos(ArrayDeListas * array, Node * lista) {
    if(lista == NULL) {
        return 0;
    }
    if(array[lista->value].julius) {
        return 1;
    }
    return checkVizinhos(array, lista->next);
}

int checkForJulius(ArrayDeListas * array, int lugar) {
    if(array[lugar].julius == 1) {
        return 1;
    }
    if(checkVizinhos(array, array[lugar].lista)) {
        return 1;
    }
    return 0;
}

int main() {
    Node * lista = NULL;
    ArrayDeListas * array;
    int nLugares, nJulius, nMalvo, nVizinhos, vizinho;

    scanf("%d", &nLugares);
    scanf("%d", &nJulius);
    scanf("%d", &nMalvo);

    array = malloc(nLugares * sizeof(ArrayDeListas));

    for(int i = 0; i < nLugares; i++) {
        array[i].julius = 0;
        scanf("%d", &nVizinhos);
        for(int j = 0; j < nVizinhos; j++) {
            scanf("%d", &vizinho);
            array[i].lista = addLista(array[i].lista, vizinho);
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