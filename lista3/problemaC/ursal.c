#include <stdio.h>
#include <stdlib.h>

void mergeAB(int * c, int * a, int m, int * b, int n) {
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < m && j < n) {
        if(a[i] <= b[j]) {
            c[k++] = a[i++];
        }else {
            c[k++] = b[j++];
        }
    }
    while(i < m) {
        c[k++] = a[i++];
    }
    while(j < n) {
        c[k++] = b[j++];
    }
}

void merge(int * v, int l, int middle, int r) {
    int * c = malloc((r - l + 1) * sizeof(int));

    mergeAB(c, &v[l], middle - l + 1, &v[middle+1], r - middle);
    
    int k = 0, i = l;
    while(i <= r) {
        v[i++] = c[k++];
    }
    free(c);
}
void mergeSort(int * v, int l, int r) {
    if(l == r ) return;
    int meio = (r + l) / 2;
    mergeSort(v, l, meio);
    mergeSort(v, meio + 1, r);
    merge(v, l, meio, r);
    
}

int countColorsNot0(int * colorArray, int size) {
    int color = colorArray[0];
    int colorAux = colorArray[0];
    int colorTimes = 1;
    int colorTimesAux = 1;
    for(int i = 1; i < size; i++) {
        if(color == colorArray[i] && colorArray[i] != 0) {
            colorTimes++;
        }
        if(colorAux == colorArray[i] && colorArray[i] != 0) {
            colorTimesAux++;
        }else if(colorArray[i] != 0) {
            colorAux = colorArray[i];
            colorTimesAux = 1;
        }
        if(colorTimesAux > colorTimes) {
            color = colorAux;
            colorTimes = colorTimesAux;
        }
    }

    return color;
}

int countColorsAndTimesNot0(int * colorArray, int size) {
    int color = colorArray[0];
    int colorAux = colorArray[0];
    int colorTimes = 1;
    int colorTimesAux = 1;
    for(int i = 1; i < size; i++) {
        if(color == colorArray[i] && colorArray[i] != 0) {
            colorTimes++;
        }
        if(colorAux == colorArray[i] && colorArray[i] != 0) {
            colorTimesAux++;
        }else if(colorArray[i] != 0) {
            colorAux = colorArray[i];
            colorTimesAux = 1;
        }
        if(colorTimesAux > colorTimes) {
            color = colorAux;
            colorTimes = colorTimesAux;
        }
    }

    if(((float) colorTimes) >= (((float) size) / 100) * 51) {
        return color;
    }else {
        return 0;
    }
}

void removeNumber(int * array, int size, int number) {
    for(int i = 0; i < size; i++) {
        if(array[i] == number) {
            array[i] = 0;
        }
    }
}

int howManyNumbers(int number) {
    if(number < 10 && number > 0) {
        return 1;
    }else if(number < 100 && number > 9) {
        return 2;
    }else if(number < 1000 && number > 99) {
        return 3;
    }else if(number < 10000 && number > 999) {
        return 4;
    }else if(number < 100000 && number > 9999) {
        return 5;
    }else if(number < 1) {
        return 0;
    }
}

int main() {

    int nSenadores, nFederais, nEstaduais, input;
    int votosValidosTotais = 0, votosInvalidos = 0;

    int presidente[100000], p = 0;
    int senador[100000], s = 0;
    int federal[10000], f = 0;
    int estadual[100000], e = 0;

    int presidenteGanhador;

    int * senadoresGanhadores, sg = 0;
    int * federaisGanhadores, fg = 0;
    int * estaduaisGanhadores, eg = 0;

    scanf("%d", &nSenadores);
    scanf("%d", &nFederais);
    scanf("%d", &nEstaduais);

    senadoresGanhadores = malloc(nSenadores *  sizeof(int));
    federaisGanhadores = malloc(nFederais *  sizeof(int));
    estaduaisGanhadores = malloc(nEstaduais *  sizeof(int));

    while(scanf("%d", &input) == 1) {
        switch(howManyNumbers(input)) {
            case 2:
                presidente[p++] = input;
                votosValidosTotais++;
                break;
            case 3:
                senador[s++] = input;
                votosValidosTotais++;
                break;
            case 4:
                federal[f++] = input;
                votosValidosTotais++;
                break;
            case 5:
                estadual[e++] = input;
                votosValidosTotais++;
                break;
            case 0:
                votosInvalidos++;
                break;
        }
    }

    mergeSort(presidente, 0, p-1);
    mergeSort(senador, 0, s-1);
    mergeSort(federal, 0, f-1);
    mergeSort(estadual, 0, e-1);

    for(int i = 0; i < nSenadores; i++) {
        senadoresGanhadores[i] = countColorsNot0(senador, nSenadores);
        removeNumber(senador, nSenadores, senadoresGanhadores[i]);
    }

    for(int i = 0; i < nFederais; i++) {
        federaisGanhadores[i] = countColorsNot0(federal, nFederais);
        removeNumber(federal, nFederais, federaisGanhadores[i]);
    }

    for(int i = 0; i < nEstaduais; i++) {
        estaduaisGanhadores[i] = countColorsNot0(estadual, nEstaduais);
        removeNumber(estadual, nEstaduais, estaduaisGanhadores[i]);
    }

    printf("%d %d\n", votosValidosTotais, votosInvalidos);

    countColorsAndTimesNot0(presidente, p);

    if(presidenteGanhador == 0) {
        printf("Segundo turno\n");
    }else {
        printf("%d\n", presidenteGanhador);
    }

    printf("%d", senadoresGanhadores[0]);
    for(int i = 1; i < nSenadores; i++) {
        printf(" %d", senadoresGanhadores[i]);
    }
    printf("\n");

    printf("%d", federaisGanhadores[0]);
    for(int i = 1; i < nFederais; i++) {
        printf(" %d", federaisGanhadores[i]);
    }
    printf("\n");

    printf("%d", estaduaisGanhadores[0]);
    for(int i = 1; i < nEstaduais; i++) {
        printf(" %d", estaduaisGanhadores[i]);
    }
    printf("\n");

    return 0;
}