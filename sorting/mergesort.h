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