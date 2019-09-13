#include <stdio.h>
#include <stdlib.h>

void mergeAB(int * c, int * a, int m, int * b, int n) {
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < m && j < n) {
        if(a[i] <= b[j]) {
            c[k] = a[i];
            k++;
            i++;
        }else {
            c[k] = b[j];
            k++;
            j++;
        }
    }
    while(i < m) {
        c[k] = a[i];
        k++;
        i++;
    }
    while(j < n) {
        c[k] = b[j];
        k++;
        j++;
    }
}

void merge(int * v, int l, int middle, int r) {
    int * c = malloc((r - l + 1) * sizeof(int));

    mergeAB(c, &v[l], middle - l + 1, &v[middle+1], r - middle);
    
    int k = 0, i = l;
    while(i <= r) {
        v[i] = c[k];
        i++;
        k++; 
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

int countColors(int * colorArray, int size) {
    int color = colorArray[0];
    int colorAux = colorArray[0];
    int colorTimes = 1;
    int colorTimesAux = 1;
    for(int i = 1; i < size; i++) {
        if(color == colorArray[i]) {
            colorTimes++;
        }
        if(colorAux == colorArray[i]) {
            colorTimesAux++;
        }else {
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

int main() {
    int nOfDucks, color, counter = 0;
    int colorArray[5000];
    int responseArray[100000];


    while(scanf("%d", &nOfDucks) == 1 && nOfDucks != 0) {
        for(int i = 0; i < nOfDucks; i++) {
            scanf("%d", &colorArray[i]);
        }

        mergeSort(colorArray, 0, nOfDucks);

        color = countColors(colorArray, nOfDucks);

        responseArray[counter++] = color;

    }

    for(int i = 0; i < counter; i++) {
        printf("%d\n", responseArray[i]);
    }

    return 0;
}