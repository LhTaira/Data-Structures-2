#include <stdio.h>
#include <stdlib.h>

#define Item int
#define less(A, B) (A < B)
#define lesseq(A, B) (A <= B)
#define exchange(A, B) {int t = B; B = A; A = t;}
#define compareExchange(A, B) {if(less(A, B)) exchange(A, B);}

static int separa(int * v, int l, int r) {
  int c = v[r];
  int j = l;

  for(int i = l; i < r; i++){
    if(v[i] < c){
        exchange(v[i],v[j]);
        j++;
    }
  }
  exchange(v[j],v[r]);
  return j;
}

void quickSort(int * v, int l, int r) {
  int j;
  while(l < r){
    j = separa(v,l,r);
    if(j - l < r - j) {
      quickSort(v, l, j-1);
      l = j+ 1;
    } else {
      quickSort(v,j+1,r);
      r = j - 1;
    }
  }
  
}