#include<stdio.h>

long int max(a, b){
	return a >= b? a : b;
}

long int W[100000], V[100000], dp[1000][1001];

long int bks(long int n, long int w){
	long int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j <= w; j++)
			if(j == 0)
				dp[i][j] = 0;
			else if(W[i] <= j)
				dp[i][j] = max((i - 1 >= 0 ? dp[i - 1][j - W[i]] : 0) + V[i], i - 1 >= 0 ? dp[i - 1][j] : 0);
			else
				dp[i][j] = i - 1 >= 0 ? dp[i - 1][j] : 0;
	return dp[n - 1][w];
}

int main(){
	int t, i;
	scanf("%d\n", &t);
	for(i = 0; i < t; i++){
		long int j, n, w;
		scanf("%ld\n", &n);
		for(j = 0; j < n; j++)
			scanf("%ld%ld", &W[j], &V[j]);
		scanf("%ld", &w);
		printf("%ld\n", bks(n, w));
	}
	return 0;
}