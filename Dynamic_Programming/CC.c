#include<stdio.h>

long int dp[50][251];

long int cc(int d[], int m, int n){
	int i, j, k;
	for(i = 0; i < m; i++)
		dp[i][0] = 1;
	for(i = 0; i < m; i++)
		for(j = 1; j <= n; j++){
			dp[i][j] = 0;
			for(k = 0; k <= j; k = k + d[i])
				dp[i][j] += i - 1 >= 0 ? dp[i - 1][j - k] : j - k == 0 ? 1 : 0; 
		}
	return dp[m - 1][n];
}

int main(){
	int m, n, i, d[50];
	scanf("%d%d", &n, &m);
	for(i = 0; i < m; i++)
		scanf("%d", &d[i]);
	printf("%ld", cc(d, m, n));
	return 0;
}