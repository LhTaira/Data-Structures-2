#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item{
    char exists;
    char string[15]; 
} Item;

int h(char * string) {
    int key = 0;
    int i = 0;

    while(string[i] != '\0') {
        key += string[i]*++i;
    }
    return 19 * key;
}

int hash(char * string){
    return h(string)%101;
}

void addItem(Item * vetor, int hash, char * value, int * nItems) {
    while(vetor[hash].exists == 1) {
        if(strcmp(vetor[hash].string, value) == 0) {
            return;
        }
        hash++;
        if(hash > 101) {
            return;
        }
    }

    vetor[hash].exists =1;
    strcpy(vetor[hash].string, value);
    *nItems += 1;
}

void removeItem(Item * vetor, int hash, char * value, int * nItems) {
    while(vetor[hash].exists == 1) {
        if(strcmp(vetor[hash].string, value) == 0) {
            vetor[hash].exists = 0;
            *nItems -= 1;
            return;
        }
        hash++;
        if(hash > 101) {
            return;
        }
    }
}


int main() {
    char stringAux[19];

    int nCasos, nOperacoes, hashValue;

    scanf("%d", &nCasos);

    for(int i = 0; i < nCasos; i++) {
        Item vetor[101];
        int * nItems = malloc(sizeof(int));
        * nItems = 0;

        for(int k = 0; k < 101; k++) {
            vetor[k].exists = 0;
        }

        scanf("%d", &nOperacoes);

        for(int j = 0; j < nOperacoes; j++) {
            scanf("%s", stringAux);

            hashValue = hash(&stringAux[4]);

            switch(stringAux[0]) {
                case 'A':
                addItem(vetor, hashValue, &stringAux[4], nItems);
                break;
                case 'D':
                removeItem(vetor, hashValue, &stringAux[4], nItems);
                break;
            }
        }

        printf("%d\n", *nItems);

        for(int k = 0; k < 101; k++) {
            if(vetor[k].exists == 1) {
                printf("%d:%s\n", k, vetor[k].string);
            }
        }

    }

    return 0;
}

