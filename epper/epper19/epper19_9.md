# E-PPER 19년도 9번 문제 (c언어)
 연속해서 3개의 돈을 가질 수 없다.

1. "동적계획법 bottom-up 방식" 

1. 후위표기법
1. 배열선언: 
	1. 돈의 액수가 저장되는 money[]와 계산결과가 저장되는 배열 dq[]를 선언한다. 
	1. dp[i] = i번째까지 탐색하였을 때 돈의 액수의 최댓값		
1. 부분문제 정의: 
	1. 0,1,2 별도 계산
	1. 3번째 이상: max(dp[i-1], max(dp[i-3]+money[i-1]+money[i], dp[i-2]+money[i]))
	
** 응용**
1. 연속해서 4개가 안되는 경우? ==> 너무 복잡해서 출제 안할 듯.
	1. 0,1,2,3 별도 계산
	2. 4번째이상: ... 

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

### 유사문제 java로 풀이하기
[(백준 2156): 포도주 시식](https://www.acmicpc.net/problem/2156)
```java
import java.io.InputStreamReader;
import java.io.StringBuffer;

public class Q9{
	public static void main(String[] args){
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.pareseInt(br.readLine());
		int[] arr = new int[N];
		int [] dp = new int[N];
		for(int i=0; i < n; i++){
			arr[i] = Integer.parseInt(br.readLine());
		}
		
		if(N>=1){ // 첫잔일 경우
			dp[0] = arr[0];
		}
		
		if(N>=2){ // 두잔일 경우
			dp[1] = arr[0]+arr[1]; 
		}
		
		if(N>=3){ // 세잔일 경우
			dp[2] = Math.max(dp[1], Math.max(dp[0]+arr[2], arr[1]+arr[2]));
		}
		
		for(int i=3; i < N; i++){
			dp[i] = Math.max(dp[i-1], Math.max(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]));
		}
		System.out.println(dp[N-1]);
	}
}
```
