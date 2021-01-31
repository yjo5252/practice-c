#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc 함수가 선언된 헤더파일
#define SWAP(x, y, tmp) ((tmp)=(x), (x)=(y), (y)=(tmp))

void print_array(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int n;
	scanf("%d", &n);
	int* a = malloc(sizeof(int) * n);
	//int a[n];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	int min, temp;
	/*
	 * 1) Find the minimum element among a[i + 1] ~ a[n - 1]
	 * 2) Swap a[i] and the minimum element
	 */

	 // YOUR CODE HERE (~15 lines)	
	for (int i = 0; i < n - 1; ++i) {
		min = i;
		for (int j = i; j < n; j++) {
			if (a[min] > a[j]) min = j;
		}
		if (i != min) {
			SWAP(a[i], a[min], temp);
		}

		print_array(a, n);
	}

	return 0;
}
