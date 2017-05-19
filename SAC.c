#include<stdio.h>

long int  B[100000], A[100000];

long int cost(int len){
	for(i = 0; i < n; i++){
		dp[i][i] = B[i];
		if(i < n - 1)
			dp[i][i + 1] = B[i] > B[i + 1] ? B[i] - 1 : B[i + 1] - 1;
	}

	for(l = 3; l < n; l++)
		for(i = 0; i < n - l + 1; i++){
			j = i + l - 1;
			for(k = i; k <= j; k++)

	}

} 

int main(){
	int t, i;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
		scanf("%d", &n);
		for(j = 0; i < n; j++)
			scanf("%d", &B[i]);

	return 0;

}