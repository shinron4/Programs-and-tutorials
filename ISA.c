#include<stdio.h>
#include<math.h>

long int A[100000], C[100000], count;

void countinversion(long int p, long int r){
	if(p < r){
		long int q = (r - p + 1)/2, i = p, j = p + q, k = 0;
		countinversion(p, p + q - 1);
		countinversion(p + q, r);
		while(i < p + q && j < r + 1)
			if(A[i] <= A[j])
				C[k++] = A[i++];
			else{
				count += p + q - i;
				C[k++] = A[j++];
			}
		while(i < p + q)
			C[k++] = A[i++];
		while(j < r + 1)
			C[k++] = A[j++];
		for(i = 0; i < r - p + 1; i++)
			A[i + p] = C[i];
	}
}
int main(){
	long int t, n, output[15], i, j;
	scanf("%ld", &t);
	for(i = 0; i < t; i++){
		scanf("%ld", &n);
		for(j = 0; j < n; j++)
			scanf("%ld", &A[j]);
		count = 0;
		countinversion(0, n - 1);
		output[i] = count;
	}
	for(i = 0; i < t; i++)
		printf("%ld\n", output[i]);
	return 0;
}