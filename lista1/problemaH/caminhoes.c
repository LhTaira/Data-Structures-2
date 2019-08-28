#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pilha {
    int n;
    struct Pilha * prev;
} Pilha;

typedef struct PilhaString {
    char * n;
    struct PilhaString * prev;
} PilhaString;

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
    pilha->n = 0;
    return pilha;
}

PilhaString * appendString(PilhaString * pilha, char * elemento) {
    PilhaString * no;
    no = (PilhaString *) malloc(sizeof(PilhaString));

    no->n = (char *) malloc(4*sizeof(char));
    strcpy(no->n, elemento);
    no->prev = pilha;
    return no;
}

PilhaString * createPilhaString(PilhaString * pilha) {
    pilha = (PilhaString *) malloc(sizeof(PilhaString));
    pilha->prev = NULL;
    pilha->n = (char *) malloc(4*sizeof(char));
    return pilha;
}

PilhaString * popString(PilhaString * pilha) {
    PilhaString * aux = pilha->prev;
    free(pilha->n);
    free(pilha);
    return aux;
}

int main() {
    Pilha * pilha = NULL;
    PilhaString * response = NULL;
    pilha = createPilha(pilha);

    int numberOfTrucks;
    int * trucks;
    int * final;

    while(scanf("%d", &numberOfTrucks) == 1 && numberOfTrucks != 0) {

        int j = 0;
        int k = 0;
        int expectedTruck = 1;

        trucks = (int *) malloc((numberOfTrucks+1)*sizeof(int));
        final = (int *) malloc(numberOfTrucks*sizeof(int));

        for(j = 0; j<numberOfTrucks; j++) {
            scanf("%d", &trucks[j]);
        }

        trucks[j] = 0;
        j=0;

        while((pilha->n !=0 || trucks[j] != 0) && expectedTruck <= numberOfTrucks ) {
            if(trucks[j] == expectedTruck) {
                final[k] = expectedTruck;
                expectedTruck++;
                k++;
                j++;
            } else if(pilha->n == expectedTruck) {
                pilha = pop(pilha);
                final[k] = expectedTruck;
                expectedTruck++;
                k++;
            } else if(trucks[j] != 0) {
                pilha = append(pilha, trucks[j]);
                j++;
            } else {
                appendString(response, "no\0");
                // printf("no\n");
                // return 0;
            }
        }

        appendString(response, "yes\0");

        while(pilha->prev != NULL) {
            pilha = pop(pilha);
        }

        pilha = pop(pilha);

        free(trucks);
        free(final);
        }

    // while(response->prev != NULL) {
    //     printf("%s\n", response->n);
    //     response = popString(response);
    // }
    printf("%s\n", response->n);
    

    return 0;

}