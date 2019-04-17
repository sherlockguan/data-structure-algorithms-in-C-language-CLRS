#include<stdio.h>
int parent(int i);
int left(int i);
int right(int i);
void max_heapify(int A[],int i, int n);//maintain max heap property => parentvalue > childvalue
void build_max_heap(int A[],int n);
void heapsort(int A[],int n);
int main(void){
  int i;
  int A[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
  for(i = 0; i <= 9; i++) printf(" %d", A[i]);
  printf("\n");
  heap_sort(A, 9);
  for(i = 0; i<= 9; i++) printf(" %d", A[i]);
  printf("\n");
	return 0;
}
int parent(int i){
  return (int)((i-1)/2);
}
int left(int i){
  return 2 * i + 1;
}
int right(int i){
  return 2 * i + 2;
}
void max_heapify(int A[],int i, int n){
  int l, r, largest, tmp;
  l = left(i);
  r = right(i);
  if(l <= n && A[l] > A[i]){
    largest = l;
  }
  else{
    largest = i;
  }
  if (r <= n && A[r] > A[largest] ){
    largest = r;
  }
  if (largest != i){
    tmp = A[i];
    A[i] = A[largest];
    A[largest] = tmp;
    max_heapify(A, largest, n);
  }

}

void build_max_heap(int A[], int n){
  int i;
  for(i = parent(n); i >= 0; i--) max_heapify(A, i, n);
}
void heapsort( int A, int n){
  build_max_heap(A, n);
  int i;
  int tmp;
  for(i = n; i >= 1; i--){
    tmp = A[0];
		A[0] = A[i];
		A[i] = tmp;
		max_heapify(A, 0, i - 1);
  }
}
