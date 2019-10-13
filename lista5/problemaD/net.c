#include <stdio.h>
#include <stdlib.h>

typedef struct Connection {
    long int download;
    long int upload;
} Connection;

void mergeAB(Connection * c, Connection * a, int m, Connection * b, int n) {
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < m && j < n) {
        if(a[i].download < b[j].download) {
            c[k] = a[i];
            k++;
            i++;
        }else if(a[i].download == b[j].download){
            if(a[i].upload <= b[j].upload) {
                c[k] = a[i];
                k++;
                i++;
            }else {
                c[k] = b[j];
                k++;
                j++;
            }
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

void merge(Connection * v, int l, int middle, int r) {
    Connection * c = malloc((r - l + 1) * sizeof(Connection));

    mergeAB(c, &v[l], middle - l + 1, &v[middle+1], r - middle);
    
    int k = 0, i = l;
    while(i <= r) {
        v[i] = c[k];
        i++;
        k++; 
    }
    free(c);
}

void mergeSort(Connection * v, int l, int r) {
    if(l == r ) return;
    int meio = (r + l) / 2;
    mergeSort(v, l, meio);
    mergeSort(v, meio + 1, r);
    merge(v, l, meio, r);
}

int main() {
    long int baseDownload, baseUpload, nTests, margin, downloadAux, uploadAux, size = 0;
    long int diffDownload, diffUpload;

    Connection * connections;

    scanf("%ld", &baseDownload);
    scanf("%ld", &baseUpload);
    scanf("%ld", &margin);

    diffDownload = (long int) ((float) baseDownload * ((float) margin/100));
    diffUpload =  (long int) ((float) baseUpload * ((float) margin/100));



    scanf("%ld", &nTests);

    connections = malloc(nTests * sizeof(Connection));

    for(int i = 0; i < nTests; i++) {
        scanf("%ld/%ld", &downloadAux, &uploadAux);

        if(baseDownload - downloadAux > diffDownload || baseUpload - uploadAux > diffUpload) {
            connections[size].download = downloadAux;
            connections[size++].upload = uploadAux;
        }
    }

    if(size > 0) {
        mergeSort(connections, 0, size - 1);
    }

    for(int i = 0; i < size; i++) {
        printf("%ld/%ld\n", connections[i].download, connections[i].upload);
    }

    return 0;

}