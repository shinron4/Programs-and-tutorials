#include<stdio.h>
#include<string.h>

struct str{
	char a[100];
	long int i;
};

int A[1000000], C[1000000];
struct str H[1000000], HN[1000000];

void countsort(long int len){
	int B[100];
	long int i;
	for(i = 0; i < 100; i++)
		B[i] = 0;
	for(i = 0; i < len; i++)
		B[A[i]]++;
	for(i = 1; i < 100; i++)
		B[i] += B[i - 1];
	for(i = len - 1; i >= 0; i--){
		C[B[A[i]] - 1] = A[i];
		HN[B[A[i]] - 1].i = H[i].i;
		strcpy(HN[B[A[i]] - 1].a, H[i].a);
 		B[A[i]]--;
	}
	for(i = 0; i < len; i++){;
		if(HN[i].i < len/2)
			printf("%c ", '-');
		else
			printf("%s ", HN[i].a);
	}
}

int main(){
	long int n, i;
	scanf("%ld", &n);
	for(i = 0; i < n; i++){
		scanf("%d %s", &A[i], H[i].a);
		H[i].i = i;
	}
	countsort(n);
	return 0;
}