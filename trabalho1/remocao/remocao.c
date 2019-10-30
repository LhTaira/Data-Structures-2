#include <stdio.h>
#include <stdlib.h>

typedef struct Pointer {
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
    if(r < l || key == 0) {
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
    Pointer ** zeros = malloc(250000 * sizeof(Pointer *));
    Pointer * ptr1 = malloc(sizeof(Pointer));
    Pointer * prePtr1 = malloc(sizeof(Pointer));
    Pointer * ptr2 = malloc(sizeof(Pointer));
    Pointer * presente = malloc(sizeof(Pointer));
    Pointer * proximo = malloc(sizeof(Pointer));
    Pointer * aux;
    
    unsigned long zerosNumbers[250000];
    unsigned long auxInt[3];

    int i = 0, j = 0, z = 0;

    while(scanf("%lx %lx %lx", &auxInt[0], &auxInt[1], &auxInt[2]) == 3) {
        pointers[i].this = auxInt[0];
        pointers[i].prev = auxInt[1];
        pointers[i++].next = auxInt[2];
    }

    *ptr1 = pointers[0];
    *ptr2 = pointers[1];

    mergeSort(pointers, 0, i - 1);

    presente = binarySearch(&pointers[0], ptr1->prev, 0, i - 1);
    *prePtr1 = *presente;
    proximo = binarySearch(pointers, presente->next, 0, i - 1);

    do {
        zeros[z++] = proximo;
       
        proximo = binarySearch(pointers, proximo->next, 0, i - 1);

        presente->next = proximo->this;
        proximo->prev = presente->this;

    } while(proximo->this != ptr2->next);

    for(int c = z; c > 0; c--) {
        zerosNumbers[c] = (*zeros)->this;
        (*zeros++)->this = 0;
    }

    mergeSort(pointers, 0, i - 1);


    presente = binarySearch(pointers, prePtr1->this, 0, i - 1);

    while(presente->prev != 0) {
       aux = binarySearch(pointers, presente->prev, 0, i - 1);
       if(aux != NULL) {
           presente = aux;
       } else {
           break;
       }
    }



    do {
        printf("%lx %lx %lx\n", presente->this, presente->prev, presente->next);
        presente = binarySearch(pointers, presente->next, 0, i - 1);
    } while(presente);

    printf("\n");

    for(int c = z; c > 0; c--) {
        printf("%lx\n", zerosNumbers[c]);
    }

    return 0;
}