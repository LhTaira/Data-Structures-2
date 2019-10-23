#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item{
    int hash;
    char exists;
    char string[16]; 
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

// void addItem(Item * vetor, int hash, char * value, int * nItems) {
//     int index = hash, i = 0;

//     while(vetor[index].exists == 1) {
//         if(strcmp(vetor[index].string, value) == 0) {
//             return;
//         }
//         i++;
//         index = (hash+(i*i)+23*i) % 101;
//         if(i == 20) {
//             return;
//         }
//     }

//     vetor[index].exists = 1;
//     vetor[index].hash = hash;
//     strcpy(vetor[index].string, value);
//     *nItems += 1;
// }

// void removeItem(Item * vetor, int hash, char * value, int * nItems) {
//     int index = hash, i =0;

//     while(vetor[index].exists == 1) {
//         if(strcmp(vetor[index].string, value) == 0) {
//             vetor[index].exists = 0;
//             *nItems -= 1;
//             return;
//         }
//         i++;
//         index = (hash+(i*i)+23*i) % 101;
//         if(i == 20) {
//             return;
//         }
//     }
// }

void addItem(Item * vetor, int hash, char * value, int * nItems) {
    int index, emptyIndex = hash;

    for(int i = 0; i < 20; i++) {
        index = (hash+(i*i)+23*i) % 101;

        if(vetor[emptyIndex].exists == 1) {
            emptyIndex = index;
        }
        
        if(vetor[index].exists == 1) {
            if(!strcmp(vetor[index].string, value)) {
                return;
            }
        }

    }

    if(vetor[emptyIndex].exists == 1) {
        return;
    }

    *nItems += 1;
    strcpy(vetor[emptyIndex].string, value);
    vetor[emptyIndex].exists = 1;
    vetor[emptyIndex].hash = hash;

}

void removeItem(Item * vetor, int hash, char * value, int * nItems) {
    int index;

    for(int i = 0; i < 20; i++) {
        index = (hash+(i*i)+23*i) % 101;

        if(vetor[index].exists == 1) {
            if(!strcmp(vetor[index].string, value)) {
                *nItems -= 1;
                vetor[index].exists = 0;
                return;
            }
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

