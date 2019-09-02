#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define Item int
#define less(A, B) (A < B)
#define lesseq(A, B) (A <= B)
#define exchange(A, B) {int t = B; B = A; A = t;}
#define compareExchange(A, B) {if(less(A, B)) exchange(A, B);}

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

int main() {

    int v[5000], i = 0;

    while(scanf("%d", &v[i]) == 1) {
        i++;
    }
    quicksort(v, 0, i-1);

    printf("%d", v[0]);

    for(int j = 1; j < i; j++) {
        printf(" %d", v[j]);
    }
    printf("\n");
    return 0;
}