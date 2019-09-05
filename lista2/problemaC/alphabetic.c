#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define lessEq(A, B) A <= B
#define lessEq(A,B) strcmp(&A, &B) <=0
#define exchange(A, B) {char * t = B; B = A; A = t;}

static int separa(char ** v, int l, int r){
  char * c = v[r];
  int j = l;

  for(int i = l; i < r; i++){
    if(lessEq(v[i], c)){
        exchange(v[i],v[j]);
        j++;
    }
  }
  exchange(v[j],v[r]);
  return j;
}

void quicksort(char ** v, int l, int r){
  int j;
  if(l < r){
    j = separa(v, l, r);
     quicksort(v, l, j-1);
     quicksort(v, j+1, r);
  } else {
    return;
  }
  
}

int main() {
    int n, k;
    char ** names;
    
    scanf("%d", &n);
    names = malloc(n * 20 * sizeof(char));
    scanf("%d", &k);


    for(int i = 0; i < n; i++) {
        scanf("%s", &names[i]);
    }

    quicksort(names, 0, n-1);

    // for(int i = 0; i < ; i++) {
        printf("%s\n", &names[k-1]);
    // }


    return 0;


}