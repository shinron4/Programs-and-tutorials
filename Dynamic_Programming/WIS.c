#include<stdio.h>

long int S[10000], F[10000], W[10000], dp[10000], P[10000];

void exg(long int *a, long int *b){
	long int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}	

long int partition(long int p , long int q){
	long int x = q, j = p , i = j - 1;
	for(; j < q; j++)
		if(F[j] <= F[x]){
			i++;
			exg(&F[i], &F[j]);
			exg(&S[i], &S[j]);
			exg(&W[i], &W[j]);
		}
	i++;
	exg(&F[i], &F[j]);
	exg(&S[i], &S[j]);
	exg(&W[i], &W[j]);
	return i;
}
 
void quicksort(long int p, long int r){
	if(p < r){
		long int q = partition(p, r);
		quicksort(p, q - 1);
		quicksort(q + 1, r);
	}
}

long int pred(long int p, long int r, long int x){
	long int i, j, q;
	i = p, j = r;
	while(i < j){
		q = (i + j)/2;
		if(x <= F[q])
			j = q;
		else
			i = q + 1;
	}
	if(x >= F[i])
		return i;
	else
		return i - 1 >= p ? i - 1 : -1;
}

long int max(long int a, long int b){
	return a >= b ? a : b;
}

long int wis(long int n){
	long int i;
	quicksort(0, n - 1);
	for(i = 0; i < n; i++)
		P[i] = pred(0, n -1, S[i]);
	for(i = 0; i < n; i++)
		dp[i] =  max((P[i] >= 0 ? dp[P[i]] : 0) + W[i], i - 1 >= 0? dp[i - 1]: 0);
	return dp[n - 1];
}

int main(){
	int t, i;
	scanf("%d\n", &t);
	for(i = 0; i < t; i++){
		long int j, n;
		scanf("%ld\n", &n);
		for(j = 0; j < n; j++)
			scanf("%ld%ld%ld", &S[j], &F[j], &W[j]);
		printf("%ld\n", wis(n));
	}
	return 0;
}