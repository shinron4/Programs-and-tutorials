#include<stdio.h>

long long int A[100000], MOD;

long long int maxsub(long int l, long int h, long int q){
	long int i;
	long long int y, s;
	y = s = A[q] % MOD;
	for(i = q - 1; i >= l; i--)
		if((y = (y + A[i]) % MOD) >= s)
			s = y;
	y = s;
	for(i = q + 1; i <= h; i++)
		if((y = (y + A[i]) % MOD) >= s)
			s = y;
	return s;
}

long long int max(long long int a, long long int b, long long int c, long long int d){
	return a > b && a > c && a > d ? a : (b > c && b > d ? b : (c > d ? c : d));
}

long long int c(long int l, long int r){
	if(l < r){
		long int q = (l + r)/2;
		return max(c(l, q), c(q + 1, r), maxsub(l, r, q), maxsub(l, r, q + 1));
	}
	return A[l] % MOD;
}

int main(){
	int t, i;
	long int n, j, k;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%ld%lld", &n, &MOD);
		for(j = 0; j < n; j++)
			scanf("%lld", &A[j]);
		printf("%lld\n", c(0, n - 1));
	}
	return 0;
}