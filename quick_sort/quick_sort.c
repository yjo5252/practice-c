// 성공
// 출처 : 3-1 컴퓨터 알고리즘
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void QuickSort(int data[], int, int);
void main() {
	int i, n;
	printf("배열의 길이 입력: "); scanf("%d", &n);

	int* pt = (int*)malloc(sizeof(int) * n);
	printf("배열의 요소들을 입력: ");
	for ( i = 0; i < n; i++) scanf("%d", &pt[i]);

	QuickSort(pt, 0, n - 1);
	printf("퀵 정렬 후: ");
	for ( i = 0; i < n; i++) printf("%d ", pt[i]);
	free(pt);
}

void QuickSort(int arr[], int left, int right) {
	int num, l, r, tmp;
	if (right > left) {
		num = arr[right];
		l = left - 1;
		r = right;

		while (1) {
			while (arr[++l] < num && l < right);
			while (arr[--r] > num && left < r);
			if (l >= r) break;

			tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
		}
		tmp = arr[l];
		arr[l] = arr[right];
		arr[right] = tmp;
		
		QuickSort(arr, left, l - 1);
		QuickSort(arr, l + 1, right);
	}
}
