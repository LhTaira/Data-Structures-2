#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    struct Pilha * prev;
} Pilha;

Pilha * append(Pilha * pilha, int elemento) {
    Pilha * no;
    
    // if(pilha->prev == NULL) {
    //     pilha->n = elemento;

    //     return pilha;
    // } else {
        no = (Pilha *) malloc(sizeof(Pilha));

        no->n = elemento;
        no->prev = pilha;
    // }

    return no;
}

Pilha * pop(Pilha * pilha) {

    Pilha * aux = pilha->prev;

    free(pilha);

    return aux;
}

Pilha * createPilha(Pilha * pilha) {
    pilha = malloc(sizeof(Pilha));

    pilha->prev = NULL;

    return pilha;
}

int main() {
    
    int v[100], i=0, input, soma=0, max;
    Pilha * pilha = NULL;

    //pilha = createPilha(pilha);

    do {
        scanf("%d", &input);

        if(input!=0) {
            v[i++] = input;
        }
    }while(input != 0);

    scanf("%d", &max);

    for(int j=0; j<i; j++) {
        soma+=v[j];
        if(soma>max) {
            pilha = append(pilha, v[j]);
            soma=0;
        }
    }

    while(pilha!=NULL) {
        printf("%d\n", pilha->n);
        pilha = pop(pilha);
    }

    return 0;
}