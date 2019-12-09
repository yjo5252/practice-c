//1771105
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const long long p = 1000000007;
long factorial[4000005];
long x_after, x_before, temp, q;

void euclidean(long p, long B) {	 //B^(-1)mod p 재귀방정식 사용하여 (확장 유클리드 호제법)
	if (p % B > 0) {
		euclidean(B, p % B);
		temp = x_after;
		x_after = x_before - (p / B) * x_after; 
		x_before = temp;
	}
	else
	{
		x_after = 1;
		x_before = 0;
	}
}

int main() {
	int N, K;
	scanf("%ld %ld", &N, &K);
	factorial[0] = 1;
	factorial[1] = 1;
	for (int i = 2; i <= N; i++)
		factorial[i] = (factorial[i - 1] * i) % p;		//factorial값 전처리
	long denominator = (factorial[K] * factorial[N - K]) % p;

	euclidean(p, denominator);		// x_after = B^(-1) (mod p) = (K!(N-K)!) ^(-1) mod p
	long result = ((factorial[N] % p) * (x_after % p)) % p;
	if (result < 0) result += p;

	printf("%d\n", result);
}

