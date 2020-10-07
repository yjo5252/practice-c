# E-PPER 19년도 9번 문제 
 정사각형 좌표 프로그램

1. "동적계획법 bottom-up 방식" 
1. 0,1,2 별도 계산
1. 후위표기법



풀이법 #1
```c
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

int main(void) {
	int A[30005];
	int dp[30005];  // 동적계획법 
					// dp[k] = k번재까지의 최대값
	int ans = 0, n = 0;
	scanf("%d", &n);// 돈의 개수 

	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]); // 돈의 액수 
	}

	//첫번째 돈의 액수 
	dp[0] = A[0];

	//돈의 개수 2개 이상
	if (n > 0) dp[1] = A[0] + A[1];

	//돈의 개수 3개 이상
	if (n > 1) dp[2] = max(A[1] + A[2], dp[0] + A[2]);
	ans = max(dp[0], max(dp[1], dp[2])); // n = 3일 때 정답 

	//돈의 개수가 3보다 큰 경우
	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 1], max(dp[i - 3] + A[i - 1] + A[i], dp[i - 2] + A[i]));
		// i-1까지 최대값 / i-3까지의 최대값 + i-1번째 값 + i번째 값 / i-2 까지의 최대값 + 현재 값
		ans = max(dp[i], ans);
	}
	printf("%d", ans);

}
```


### 풀이법 1 
```c
#include <stdio.h>

// 변수 선언 
int money[30000] = {0};
int dp[30000] = {0}; // dp[k]: k번째 최대

// 함수 선언
int max(int a, int b);
int cal(int n);


int main(){
	int answer=0, n;
	scanf("%d", &n);n // 돈의 개수 
	for(int i=0; i < n; i++)
		scanf("%d", &money[i]); // 돈의 액수 
	
	answer = cal(n);
	printf("%d", answer);
	return 0;
}

int max(int a, int b){
	if (a>b)
		return a;
	else return b;
}

int cal(int n){
	dp[0] = money[0];
	dp[1] = money[0]+money[1];
	dp[2] = max(dp[1], max(money[1]+money[2], dp[0]+money[2]));
	
	for(int i=0; i< n; i++){
		dp[i] = max(dp[i-1], max(dp[i-3]+money[i-1]+money[i], dp[i-2]+money[i]));	
	}
	return dp[n-1];
}


```
