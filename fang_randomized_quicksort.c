#include <stdio.h>
/* author sherlock guan*/
//first write the quicksort then modify it to randomized_quicksort is easier to write and think
/*choose a pivot randomly based on code of quicksort -- randomized quicksort*/
int partition(int A[], int p, int r);
void random(int a, int b);
void swap(int *a, int *b);
int randomized_partition(int A[],int p, int r);// new
void randomized_quicksort(int A[], int p, int r);// new
int main(void) {
	int A[8] = { 8, 1, 6, 4, 0, 3, 9, 5 };
	int i;

	for (i = 0; i < 8; i++) printf("%d ", A[i]);
	printf("\n");

	quicksort(A, 0, 7);

	for (i = 0; i < 8; i++) printf("%d ", A[i]);
	printf("\n");

	return 0;
}
int partition(int A[], int p, int r) {
	int x;
	int i, j;

	x = A[r]; // pivot is located at the end of array after randomized_partition
	i = p - 1;
	for (j = p; j <= r - 1; j++) {
		if (A[j] <= x) {
			i = i + 1;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[i + 1], &A[r]);

	return i + 1;
}
int randomized_partition(int A[], int p, int r){
	int i;
	i = random(p, r);
	swap(&A[r], &A[i]);// pivot value is swaped with the last one of  array
	return partition(A, p, r);

}
void randomized_quicksort(int A[], int p, int r){
	int q;

	if (p < r) {
		q = randomized_partition(A, p, r);
		randomized_quicksort(A, p, q - 1);
		randomized_quicksort(A, q + 1, r);
	}
}
void swap(int *a, int *b){
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
void random(int a, int b){
	return (rand() % (b - a + 1)) + a

}
