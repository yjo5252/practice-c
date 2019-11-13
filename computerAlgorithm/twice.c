//1771105
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//euclidean
const long long p = 1000000007;
long factorial[4000005]; //euclidean
long x_after, x_before, temp, q;
//fermat
#define P 1000000007LL	
typedef long long ll;
ll fac[4000005], n, k, inv[4000005];//inv[x]�� ���Ǵ� x��inverse�� �ƴ� x!�� inverse

void euclidean(long p, long B) {	 //B^(-1)mod p ��͹����� ����Ͽ� (Ȯ�� ��Ŭ���� ȣ����)
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

ll power(ll x, ll y) {    //���� ������ �̿��Ͽ� x^y ���ϱ�
	ll ret = 1;
	while (y > 0) {
		if (y % 2) {
			ret *= x;
			ret %= P;
		}
		x *= x;
		x %= P;
		y /= 2;
	}
	return ret;
}
int main() {

	//euclidean
	int N, K;
	//scanf("%ld %ld", &N, &K);
	scanf("%lld %lld", &n, &k);
	N = (long)n, K = (long)k;
	factorial[0] = 1;
	factorial[1] = 1;
	for (int i = 2; i <= N; i++)
		factorial[i] = (factorial[i - 1] * i) % p;		//factorial�� ��ó��
	long denominator = (factorial[K] * factorial[N - K]) % p;

	euclidean(p, denominator);		// x_after = B^(-1) (mod p) = (K!(N-K)!) ^(-1) mod p
	long result = ((factorial[N] % p) * (x_after % p)) % p;
	if (result < 0) result += p;

	printf("euclidean: %d\n", result);

	// fermat
	fac[1] = 1;
	for (int i = 2; i <= 4000000; i++)
		fac[i] = (fac[i - 1] * i) % P;            //factorial ��ó��
	inv[4000000] = power(fac[4000000], P - 2);    //�丣���� �������� �̿��Ͽ� fac(400��)�� inverse�� ����(�̶� ���� ������ �̿��Ͽ� logP�� �ð��� ó��) 
	for (int i = 4000000 - 1; i > 0; i--)
		inv[i] = (inv[i + 1] * (i + 1)) % P;    //inverse(fac(i))=inverse(fac(i+1))*(i+1)�̶�� ������ �̿��Ͽ� ��ó��
	//�� O(N+logP)�ð��� ��ó���� ���� 
	//��ó���� ������ ������ � ������ ���͵� ����ð��� ���� ����� ��� ����
	
	//scanf("%lld%lld", &n, &k);
	if (n == k || !k) {
		puts("1");
		return 0;
	}
	ll r = (fac[n] * inv[n - k]) % P;
	r = (r * inv[k]) % P;
	printf("fermat: %lld\n", r);
	return 0;
}
;
