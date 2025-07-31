
#include<stdio.h>
#define N 20
void fn_initializearray(int a[]) {
	for (int i = 0; i < N; i++) {
		a[i] = i + 1;

	}
}

void fn_computesquare_srl(int a[], int square[]) {
	for (int i = 0; i < N; i++) {
		square[i] = a[i] * a[i];
		printf("Square of a[%d]: a[%d]*2=%d\n", i, a[i], square[i]);
	}
}


void fn_display(int square[]) {
	printf("\n square result\n");
	for (int i = 0; i < N; i++) {
		printf("square[%d]=%d\n", i, square[i]);
	}
}


int fn_num_square() {
	int a[N], square[N];
	fn_initializearray(a);
	fn_computesquare_srl(a, square);
	fn_display(square);
	return 0;
}