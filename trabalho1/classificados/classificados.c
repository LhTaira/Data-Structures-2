#include <stdio.h>
#include <stdlib.h>

#define exchange(a, b) {Semente d = a; a = b; b = d;}

typedef struct Semente {
    int id;
    int nota;
} Semente;

void mergeAB(Semente * c, Semente * a, int m, Semente * b, int n) {
    int i = 0, j = 0, k = 0;
    
    while(i < m && j < n) {
        if(a[i].id <= b[j].id) {
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

void merge(Semente * v, int l, int middle, int r) {
    Semente * c = malloc((r - l + 1) * sizeof(Semente));

    mergeAB(c, &v[l], middle - l + 1, &v[middle+1], r - middle);
    
    int k = 0, i = l;
    while(i <= r) {
        v[i++] = c[k++];
    }
    free(c);
}

void mergeSort(Semente * v, int l, int r) {
    if(l == r ) return;
    int meio = (r + l) / 2;
    mergeSort(v, l, meio);
    mergeSort(v, meio + 1, r);
    merge(v, l, meio, r);
    
}

int less(Semente a, Semente b) {
    if(a.nota < b.nota)
        return 1;

    if(a.nota == b.nota)
        if(a.id < b.id )
            return 1;
            
    return 0;
}

int lessEq(Semente a, Semente b) {
    if(a.nota < b.nota)
        return 1;

    if(a.nota == b.nota)
        if(a.id <= b.id )
            return 1;
            
    return 0;
}

int separa(Semente * v, int l, int r) {
    exchange(v[((r + l) / 2)], v[r]);
    
    Semente c = v[r];
    int j = l;

    for(int i = l; i < r; i++){
        if(lessEq(v[i], c)) {
            exchange(v[i],v[j]);
            j++;
        }
    }
    exchange(v[j],v[r]);
    return j;
}

void encontraEColoca(Semente * v, int l, int r, int target) {
   int j = separa(v, l, r);

    if(j == target){
        return;
    }

    if(j < target) {
        encontraEColoca(v, j + 1, r, target);
    }

    if(j > target) {
        encontraEColoca(v, l, j - 1, target);
    }
}

int main() {
    Semente * sementes = malloc(10000000 * sizeof(Semente));
    int k, size = 0, aux1, aux2;

    scanf("%d", &k);

    while(scanf("%d %d", &aux1, &aux2) == 2) {
        sementes[size].id = aux1;
        sementes[size].nota = aux2;
        size++;
    }

    // for(int i = 0; i < k; i++) {
        encontraEColoca(sementes, 0, size - 1, k - 1);
    // } 

    mergeSort(sementes, 0, k - 1);

    for(int i = 0; i < k; i++) {
        printf("%d %d\n", sementes[i].id, sementes[i].nota);
    }

    return 0;

}
