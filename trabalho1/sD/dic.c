#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getOcorrencias(char * str1, char * str2) {
    int ocorrencias = 0, i = 0;
    char * ptr = str1;

    do {
        ptr = strstr(ptr, str2);
        if(ptr) {
            ocorrencias++;
            ptr++;
        }
    } while(ptr);

    return ocorrencias;
}

int main() {
    char * array[100001];
    // char aux[4194305];
    int i = 0;

    array[0] = malloc(4194305 * sizeof(char));
    while(scanf("%s", array[i]) == 1) {
        array[i + 1] = malloc(4194305 * sizeof(char));
        // strcpy(array[i], aux);
        i++;
    }
    i--;
    for(int j = 0; j < i; j++) {
        printf("%d\n", getOcorrencias(array[j], array[i]));
    }

    return 0;
}