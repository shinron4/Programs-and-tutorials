#include <iostream>

using namespace std;

int bsearch(int A[], int i, int j, int x){
	int mid;
	while(i < j){
		mid = (i + j) >> 1;
		if(x <= A[mid]) j = mid;
		else i = mid + 1;
	}
	return i;
}

int lis(int A[], int n){
	int l[n], k = 0;
	l[k++] = A[0];
	for(int i = 1; i < n; i++){
		int j = bsearch(l, 0, k - 1, A[i]);
		l[A[i] <= l[j] ? j : k++] = A[i];
	}
	return k;
}

int main(){
	int t, n, a[1000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> a[j];
		cout << lis(a, n) << "\n";
	}
	return 0;
}

