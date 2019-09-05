#include <stdio.h>
#include <stdlib.h>

#define exchange(A, B) {int t = B; B = A; A = t;}

static int separa(int * v, int l, int r){
  int c = v[r];
  int j = l;

  for(int i = l; i < r; i++){
    if(v[i] <= c){
        exchange(v[i],v[j]);
        j++;
    }
  }
  exchange(v[j],v[r]);

  return j;
}

void quicksort(int * v, int l, int r){
  int j;
  if( l < r){
    j = separa(v,l,r);
     quicksort(v,l,j-1);
     quicksort(v,j+1,r);
  } else {
    return;
  }
  
}

int binarySearch(int * low, int key, int * high) {
    if(low > high) {
        return 0;
    }else if( key == *(low + (high - low)/2)) {
        return 1;
    }else if(key > *(low + (high - low)/2)) {
        if(binarySearch((low + (high - low)/2) +1, key, high) == 1) {
            return 1;
        } else {
            return 0;
        }
    }else if(key < *(low + (high - low)/2)) {
        if(binarySearch(low, key, (low + (high - low)/2) - 1) == 1) {
            return 1;
        } else {
            return 0;
        }
    }
   
}

// int binarySearch(int * array, int len, int key) {
//     int low = 0, high = len -1, currentIndex;

//     while(low <= high) {
//         currentIndex = (high + low) / 2;
//         if(key == array[currentIndex])
//             return currentIndex;
//         else if(key < array[currentIndex])
//             high = currentIndex - 1;
//         else
//             low = currentIndex +1;
//     }

//     return -1;
// }
 
int main() {
    int size, j = 0, number;
    int * array;

    char * yesNo;

    scanf("%d", &size);

    array = malloc(2*size*sizeof(int));
    yesNo = malloc(8*size*sizeof(char));

    for(int i=0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    quicksort(array, 0, size-1);

    while(scanf("%d", &number) == 1) {
        if(binarySearch(array, number, array + size) == 1) {
            yesNo[j++] = 1;
        } else {
            yesNo[j++] = 0;
        }
    }

    for(int i = 0; i < j; i++) {
        if(yesNo[i] == 1) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }
    }

    free(array);
    free(yesNo);

    return 0;

}