#include<stdio.h>

long int D[100001], dp[10000][10000];

long int mcm(long int n){
	long int l, i, j, min, q;
	for(i = 0; i < n; i++){
		dp[i][i] = 0;
		if(i < n - 1)
			dp[i][i + 1] = D[i]*D[i + 1]*D[i + 2];
	}
	for(l = 3; l <= n; l++)
		for(i = 0; i < n - l + 1; i++){
			dp[i][i + l - 1] = 1000000;
			for(j = i; j < i + l - 1; j++){
				q = dp[i][j] + dp[j + 1][i + l - 1] + D[i]*D[j + 1]*D[i + l];
				if(q < dp[i][i + l - 1])
					dp[i][i + l - 1] = q;
			}
		}
	return dp[0][n - 1];
}

int main(){
	int t, i;
	scanf("%d\n", &t);
	for(i = 0; i < t; i++){
		long int n, j;
		scanf("%ld", &n);
		for(j = 0; j <= n; j++)
			scanf("%ld", &D[j]);
		printf("%ld\n", mcm(n));
	}
	return 0;
}