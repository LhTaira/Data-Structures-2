#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item{
    struct Item * next; 
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

Item * createList(char * value, int * howManyShitsAreThere) {
    (*howManyShitsAreThere)++;
    Item * lista = malloc(sizeof(Item));

    lista->next = NULL;
    strcpy(lista->string, value);

    return lista;
}

Item * push(Item * lista, char * value, int * howManyShitsAreThere) {
    Item * listaAux = lista;
    if(lista == NULL) {
        return createList(value, howManyShitsAreThere);
    }

    while(listaAux->next != NULL) {
        // printf("%s\n%s\n\n\n", listaAux->string, value);
        if(strcmp(listaAux->string, value) == 0) {
            return lista;
        }

        listaAux = listaAux->next;
    }

    if(strcmp(listaAux->string, value) == 0) {
        return lista;
    }

    listaAux->next = createList(value, howManyShitsAreThere);
    return lista;
}

Item * removeItem(Item * lista, char * value, int * howManyShitsAreThere) {
    Item * listaAux = lista;
    if(lista != NULL) {
        if(strcmp(lista->string, value) == 0) {
            (*howManyShitsAreThere)--;
            free(lista);
            return NULL;
        } else {
            while(listaAux->next != NULL){
                if(strcmp(lista->next->string, value) == 0) {
                    (*howManyShitsAreThere)--;
                free(listaAux->next);
                return listaAux;
                } else {
                    listaAux = lista ->next;
                }
            }
        }
    } else {
        return NULL;
    }
}

int main() {
    char stringAux[19];

    int nCasos, nOperacoes, hashValue;



    scanf("%d", &nCasos);

    for(int i = 0; i < nCasos; i++) {
        Item * vetorDeListas[101];
        int * howManyShitsAreThere = malloc(sizeof(int));
        * howManyShitsAreThere = 0;

        for(int i = 0; i < 101; i++) {
            vetorDeListas[i] = NULL;
        }

        scanf("%d", &nOperacoes);

        for(int j = 0; j < nOperacoes; j++) {
            scanf("%s", stringAux);

            hashValue = hash(&stringAux[4]);

            switch(stringAux[0]) {
                case 'A':
                vetorDeListas[hashValue] = push(vetorDeListas[hashValue], &stringAux[4], howManyShitsAreThere);
                break;
                case 'D':
                vetorDeListas[hashValue] = removeItem(vetorDeListas[hashValue], &stringAux[4], howManyShitsAreThere);
                break;
            }
        }

    printf("%d\n", *howManyShitsAreThere);

        for(int j = 0; j < 101; j++) {
            while(vetorDeListas[j] != NULL) {
                printf("%d:%s\n", j, vetorDeListas[j]->string);
                vetorDeListas[j] = vetorDeListas[j]->next;
            }
        }

    }

}

