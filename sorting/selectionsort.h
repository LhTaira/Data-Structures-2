#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A < B)
#define exchange(A, B) {int t = B; B = A; A = t;}

void selectionSort(int * v, int l, int r) {
    int menor;
    for(int i = l; i < r; i++) {
        menor = i;
        for(int j = i; j < r; j++) {
            if(v[j] < v[menor]) {
                menor = j;
            }
        }
        exchange(v[i], v[menor]);
    }
}