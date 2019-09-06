#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define lessEq(A, B) A <= B
// #define lessEq(A,B) strcmp(&A, &B) <=0
#define exchange(A, B) {char * t = B; B = A; A = t;}

static int separa(char ** v, int l, int r) {
  char * c = v[r];
  int j = l;

  for(int i = l; i < r; i++){
    if(strcmp(v[i], c) <= 0){
        exchange(v[i],v[j]);
        j++;
    }
  }
  exchange(v[j],v[r]);
  return j;
}

void quicksort(char ** v, int l, int r) {
  int j;
  while(l < r){
    j = separa(v,l,r);
    if(j - l < r - j) {
      quicksort(v, l, j-1);
      l = j+ 1;
    } else {
      quicksort(v,j+1,r);
      // return;
      r = j - 1;
    }
  }
  
}

int main() {
    int n, k;
    char ** names;
    
    scanf("%d", &n);
    scanf("%d", &k); 

    names = malloc(n * sizeof(char *));
    for(int i = 0; i < n; i++) {
      names[i] = malloc(21 * sizeof(char));
    }

    for(int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    quicksort(names, 0, n-1);

    printf("%s\n", names[k-1]);

    // for(int i = 0; i < n; i++) {
    //     printf("%s\n", names[i]);
    // }


    return 0;


}