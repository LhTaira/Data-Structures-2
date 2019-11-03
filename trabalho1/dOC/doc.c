#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * copiaString(char * str1) {
    int i = 0, j = 0, at = 0, plus = 0;
    char * str2 = malloc(101 * sizeof(char));

    while(str1[i] != '\0') {
        if(str1[i] == '+') {
            plus = 1;
        }else if(str1[i] == '@') {
            at = 1;
            plus = 0;
            str2[j++] = str1[i];
        }else if((str1[i] != '.' || at == 1) && plus == 0) {
            str2[j++] = str1[i];
        }
        i++;
    }
    str2[j] = str1[i];
    return str2;
}

int compareWithEverything(char ** array, char * string, int size) {
    for(int i = 0; i < size; i++) {
        if(strcmp(array[i], string) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char * aux2, * array[1000], aux[101];
    int j = 0, nStrings;

    scanf("%d", &nStrings);

    for(int i = 0; i < nStrings; i++) {
        scanf("%s", aux);
        aux2 = copiaString(aux);
        if(!compareWithEverything(array, aux2, j)) {
            array[j++] = aux2;
        }
    }

    printf("%d\n", j);
    return 0;

}