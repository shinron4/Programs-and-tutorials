#include<stdio.h>
#include<stdlib.h>

int A[10000], B[10000];

int partition(int p , int q){
	int x = q, j = p , i = j - 1, temp;
	for(; j < q; j++)
		if(A[j] <= A[x]){
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	i++;
	temp = A[i];
	A[i] = A[x];
	A[x] = temp;
 
	return i;
}
 
void quicksort(int p, int r){
	if(p < r){
		int q = partition(p, r);
		quicksort(p, q - 1);
		quicksort(q + 1, r);
	}
}

int opt(int a, int b){
	int x;
	a = abs(a - b);
	x = a/5;
	if((a - x * 5) % 2 == 0)
		return x + (a - x * 5)/2;
	else
		return x + (a - x * 5)/2 + 1;
}

int e(int n){
	int x = (A[1] - A[0]) % 5, t1 = opt(A[1], A[0]), val = A[1] - A[0], u = A[1], j, t2 = t1;
	for(j = 2; j < n; j++){
		B[j] += val;
		t1 += opt(u, B[j]);
		val += B[j] - u;
		u = B[j];
	}
	val = A[1] - A[0], u = A[1];
	for(j = 0; j < n; j++)
		B[j] = A[j];
	if(x == 3)
		opt(A[1] + 2, A[2] + val + 4) < opt(A[1], A[2] + val) ? val += 4, u += 2 : 0;
	else if(x == 4)
		opt(A[1] + 1, A[2] + val + 2) < opt(A[1], A[2] + val) ? val += 2, u += 1 : 0;
	for(j = 2; j < n; j++){
		B[j] += val;
		t2 += opt(u, B[j]);
		val += B[j] - u;
		u = B[j];
	}
	return t1 <= t2 ? t1 : t2;
}

int main(){
	int t, i;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		int n, j;
		scanf("%d", &n);
		for(j = 0; j < n; j++)
			scanf("%d", &A[j]);
		quicksort(0, n - 1);
		for(j = 0; j < n; j++)
			B[j] = A[j];
		printf("%d\n", e(n));
	}
	return 0;
}
