#include<stdio.h>

int A[100000];

long int maxsub(long int l, long int h, long int q){
	long int y, s, i;
	y = s = A[q];
	for(i = q - 1; i >= l; i--)
		if((y += A[i]) >= s)
			s = y;
	y = s;
	for(i = q + 1; i <= h; i++)
		if((y += A[i]) >= s)
			s = y;
	return s;
}

long int max(long int a, long int b, long int c){
	return a > b && a > c ? a : (b > c ? b : c);
}

long int c(long int l, long int r){
	if(l < r){
		long int q = (l + r)/2;
		return max(c(l, q), c(q + 1, r), maxsub(l, q, q) + maxsub(q + 1, r, q + 1));
	}
	return A[l];
}

long int nc(long int n){
	int  max = -20000, f = -1;
	long int s = 0, i;
	for(i = 0; i < n; i++)
		if(A[i] >= 0){
			s += A[i];
			f = 1;
		}
		else if(A[i] > max)
			max = A[i];
	return f == 1 ? s : max;
}

int main(){
	int t, i;
	long int n, j, k;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%ld", &n);
		for(j = 0; j < n; j++)
			scanf("%d", &A[j]);
		printf("%ld %ld\n", c(0, n - 1), nc(n));
	}
	return 0;
}