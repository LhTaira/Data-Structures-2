#include <stdio.h>

int main() {
    int n, soma=0, aux;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%d", &aux);
        soma += aux;
    }

    printf("%d\n", soma);

    return 0;
}