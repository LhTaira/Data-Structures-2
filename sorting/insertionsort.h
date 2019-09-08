#include <stdio.h>
#include <stdlib.h>

#define exchange(A, B) {int t = B; B = A; A = t;}

void insertionSort(int * v, int l, int r) {
    for(int i = l + 1; i <= r; i++) {
        for(int j = i; j > l; j--) {
            if(v[j] < v[j - 1]) {
                exchange(v[j - 1], v[j]);
            }
        }
    }
}