//epper18_7.c
// 입력된 점수들 -> 오름차순 정리 -> 평균 최대값 

#include <stdio.h>
#include <stdlib.h> //qsort 선언 library

int ascending(const void* a, const void* b); // 정렬을 오름차순으로 한다. 

int main() {
	int n;
	int i = 0;
	int* score;
	float avg;

		scanf("%d", &n);
		score = (int*) malloc(sizeof(int)*n);

		for (i = 0; i < n; i++) {
			scanf("%d", &score[i]);
		}
    /// 정렬할 배열, 요소 개수, 요소 크기, 비교 함수를 넣어줌
		qsort(score, n, sizeof(int),ascending);// quick sort
    
		i = 0;

		if (n == 1) avg = score[i];					 
		else {
			avg = (score[i] + score[i + 1]) / 2.0; //연속된 두 수의 평균
			i += 2;
			while (i != n) {
				avg = (score[i] + avg) / 2.0;
				i++;
			}
		}
		prinf("%0.6f", avg); //소수점 6째자리
}
int ascending(const void* a, const void* b) {
	if (*(int*)a > * (int*)b)
		return 1;a
	else if (*(int*)a < *(int*)b)
		return -1;
	else
		return 0;
}
