#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int n;
    struct Pilha * prev;
} Pilha;

Pilha * append(Pilha * pilha, int elemento) {
    Pilha * no;
    no = (Pilha *) malloc(sizeof(Pilha));

    no->n = elemento;
    no->prev = pilha;

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
    int n, numeroDeGalhos, galhoAqui = 0;
    int * lado;
    char * altura;
    Pilha * pilha;

    scanf("%d",&tamanhoArvore);

    scanf("%d",&numeroDeGalhos);

    altura = malloc(numeroDeGalhos*sizeof(int));
    lado = malloc(numeroDeGalhos*sizeof(char));

    pilha = createPilha(pilha);
    
    for(int i=0; i<numeroDeGalhos; i++) {
        scanf("%d", &lado[i]);
        scanf("%c", &altura[i]);
    }

    for(int i=tamanhoArvore-1; i!=0; i++) {
        for(int j=0; j<numeroDeGalhos; j++) {
            if(altura[j] == i) {
                galhoAqui = 1;
            }

            if(galhoAqui==1) {
                if(lado[i] == 'E') {
                    pilha = append(pilha, 0);
                } else if(lado[i] == 'D') {
                    pilha = append(pilha, 2);    
                } else {
                    printf("lol\n");
                }
            } else {
                pilha = append(pilha, 1);
            }
        }
    }

}