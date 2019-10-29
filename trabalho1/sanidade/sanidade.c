#include <stdio.h>
#include <stdlib.h>

typedef struct Pointer{
    unsigned long this;
    unsigned long next;
    unsigned long prev;
} Pointer;

void mergeAB(Pointer * c, Pointer * a, int m, Pointer * b, int n) {
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < m && j < n) {
        if(a[i].this <= b[j].this) {
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

void merge(Pointer * v, int l, int middle, int r) {
    Pointer * c = malloc((r - l + 1) * sizeof(Pointer));

    mergeAB(c, &v[l], middle - l + 1, &v[middle+1], r - middle);
    
    int k = 0, i = l;
    while(i <= r) {
        v[i++] = c[k++];
    }
    free(c);
}

void mergeSort(Pointer * v, int l, int r) {
    if(l == r ) return;
    int meio = (r + l) / 2;
    mergeSort(v, l, meio);
    mergeSort(v, meio + 1, r);
    merge(v, l, meio, r);
    
}

Pointer * binarySearch(Pointer * vetor, long unsigned key, int l, int r) {
    if(r < l) {
        return NULL;
    }

    int meio = (r + l)/2;

    if(key == vetor[meio].this) {
        return &vetor[meio];
    }

    if(key < vetor[meio].this) {
        return binarySearch(vetor, key, l, meio - 1);
    }
    
    return binarySearch(vetor, key, meio + 1, r);

}

int main() {

    Pointer pointers[250000];
    Pointer * ptr1 = malloc(sizeof(Pointer));
    Pointer * ptr2 = malloc(sizeof(Pointer));
    Pointer * presente = malloc(sizeof(Pointer));
    Pointer * proximo = malloc(sizeof(Pointer));
    
    unsigned long auxInt[3];
    int i = 0, j = 0;

    while(scanf("%lx %lx %lx", &auxInt[0], &auxInt[1], &auxInt[2]) == 3) {
        pointers[i].this = auxInt[0];
        pointers[i].prev = auxInt[1];
        pointers[i++].next = auxInt[2];
    }

    *ptr1 = pointers[0];
    *ptr2 = pointers[1];
    *presente = *ptr1;
    *proximo = *ptr1;

    mergeSort(pointers, 0, i - 1);

    for(j = 0; presente->this != ptr2->this; j++) {
        proximo = binarySearch(&pointers[0], presente->next, 0, i - 1);

        if(proximo == NULL) {
            printf("insana\n");
            return 0;
        }
        // printf("this: %lx\n", proximo->this);

        if(proximo->prev != presente->this) {
            printf("insana\n");
            return 0;
        }
        
        presente = proximo;
    }

    printf("sana\n");


    return 0;
}