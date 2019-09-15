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
    if(l >= r ) return;
    int meio = (r + l) / 2;
    mergeSort(v, l, meio);
    mergeSort(v, meio + 1, r);
    merge(v, l, meio, r);
}

int * intercala2(int * v1, int s1, int * v2, int s2) {
    int c1 = 0;
    int c2 = 0;
    int c3 = 0;

    int * v3 = malloc((s1 + s2) * sizeof(int));

    while(c1 < s1 && c2 < s2) {
        if(v1[c1] <= v2[c2]) {
            v3[c3++] = v1[c1++];
        }else {
            v3[c3++] = v2[c2++];
        }
    }
    while(c1 < s1) {
        v3[c3++] = v1[c1++];
    }
    while(c2 < s2) {
        v3[c3++] = v2[c2++];
    }

    return v3;
}

int * intercala4(int * v1, int s1, int * v2, int s2, int * v3, int s3, int * v4, int s4) {
    int * v5 = malloc((s1 + s2 + s3 + s4) * sizeof(int));

    v5 = intercala2(intercala2(v1, s1, v2, s2), s1 + s2, intercala2(v3, s3, v4, s4), s3 + s4);
    return v5;
}

int * intercala8(int * v1, int s1, int * v2, int s2, int * v3, int s3, int * v4, int s4, int * v5, int s5, int * v6, int s6, int * v7, int s7, int * v8, int s8) {
    int * v9 = malloc((s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8) * sizeof(int));

    v9 = intercala2(intercala4(v1, s1, v2, s2, v3, s3, v4, s4), s1 + s2 + s3 + s4, intercala4(v5, s5, v6, s6, v7, s7, v8, s8), s5 + s6 + s7 + s8);
    return v9;
}

int main() {
    int s[8];

    int * vFinal;

    int ** v;

    v = malloc(8 * sizeof(int *));

    for(int i = 0; i < 8; i++) {
        scanf("%d", &s[i]);
        v[i] = malloc(s[i] * sizeof(int));
        for(int j = 0; j < s[i]; j++) {
            scanf("%d", &v[i][j]);
        }
    }

    // for(int i = 0; i < 8; i++) {
    //     mergeSort(v[i] , 0, s[i] - 1);
    // }

    vFinal = intercala8(v[0], s[0], v[1], s[1], v[2], s[2], v[3], s[3], v[4], s[4], v[5], s[5], v[6], s[6], v[7], s[7]);

    // mergeSort(vFinal, 0, s[1] + s[2] + s[3] + s[4] + s[5] + s[6] + s[7] + s[8]);

    printf("%d", vFinal[0]);
    for(int i = 1; i < s[1] + s[2] + s[3] + s[4] + s[5] + s[6] + s[7] + s[0]; i++) {
        printf(" %d", vFinal[i]);
    }
    printf("\n");

    return 0;
}
