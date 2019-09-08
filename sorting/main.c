#include "quicksort.h"
#include "mergesort.h"
#include "selectionsort.h"
#include "insertionsort.h"

int main() {
    int choice, i = 0, v[10000];
    printf("1: selection\n2: insertion\n3: quick\n4: merge\n");
    scanf("%d", &choice);

    while(scanf("%d", &v[i]) == 1) {
        i++;
    }

    switch (choice) {
        case 1:
            selectionSort(v, 0, i - 1);
            break;
        case 2:
            insertionSort(v, 0, i - 1);
            break;
        case 3:
            quickSort(v, 0, i - 1);
            break;
        case 4:
            mergeSort(v, 0, i - 1);
            break;
    }
    printf("\n");
    for(int j = 0; j < i; j++) {
        printf("%d\n", v[j]);
    }
}