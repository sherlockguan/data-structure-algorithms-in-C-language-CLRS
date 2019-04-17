/*quick sort 
author sherlock guan*/

#include<stdio.h>
void quicksort(int A[], int p, int r);
int partition(int A[], int p, int r);
int main(void){
  int i;
  int A[8] = {8, 1, 6, 4, 0, 3, 9, 5};
  for(i = 0; i < 8; i++) printf(" %d", A[i]);
  printf("\n");
  quicksort(A, 0, 7);
  for(i = 0; i < 8; i++) printf(" %d", A[i]);
  printf("\n");
  return 0;
}
void quicksort(int A[], int p, int r){
  int q ;
  if(p < r){

    q = partition(A, p,r);
    quicksort(A, p, q - 1);
    quicksort(A, q + 1, r);
  }
}

int partition(int A[], int p, int r){
  int x, i, j, tmp;
  x = A[r];//pivot
  i = p - 1;
  for(j = p; j < r; j++){
    if(A[j] <= x){
      i += 1;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }

  }
  tmp = A[i + 1];
  A[i + 1] = A[r];
  A[r] = tmp;
  return i + 1 ;// pivot index position after sorting

}
