#include <stdio.h>

#define less(A, B) (A < B)
#define exchange(A, B) {int t = B; B = A; A = t;}
#define compareExchange(A, B) {if(less(A, B)) exchange(A, B);}

void insertionSort(int * v, int l, int r) {
    int i, j;
    for(i = r; i >= l; i--) {
        compareExchange(v[i], v[i-1]);
    }
    for(i = l + 1; i <= r; i++) {
        int menor = v[i];
        j = i;
        while(less(menor, v[j-1])) {
            v[j] = v[j-1];
            j--;
        }
        v[j] = menor;
    }
}

int main() {
    int v[1000];
    int i = 0, j = 0;

    while(scanf("%d", &v[i++]) == 1);

    insertionSort(v, 0, --i-1);
    
    printf("%d", v[j++]);

    while(j<i) {
        printf(" %d", v[j++]);
    }
    

    printf("\n");


}