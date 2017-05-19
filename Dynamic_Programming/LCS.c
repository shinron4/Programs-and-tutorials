#include<stdio.h>
#include<string.h>

long int max(a, b){	
	return a >= b? a : b;
}

char A[100000], B[100000], dp[10000][10000];

long int lcs(long int m, long int n){
	long int i, j;
	for(i = 0; i < m; i++)
		for(j = 0; j < n; j++)
			if(A[i] == B[j])
				dp[i][j] = (i - 1 >= 0 && j - 1 >= 0 ? dp[i - 1][j - 1] : 0) + 1;
			else
				dp[i][j] = max(i - 1 >= 0 && j >= 0 ? dp[i - 1][j] : 0, i >= 0 && j - 1 >= 0 ? dp[i][j - 1] : 0);
	return dp[m - 1][n -1];
}

int main(){
	int t, i;
	scanf("%d\n", &t);
	for(i = 0; i < t; i++){
		long int m, n;
		scanf("%s", A);
		scanf("%s", B);
		m = strlen(A), n = strlen(B);
		printf("%ld\n", lcs(m, n));
	}
	return 0;
}