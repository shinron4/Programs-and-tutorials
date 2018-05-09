#include <iostream>
#include <cmath>

using namespace std;

void sumoversubset(int A[], int n, int f[]){
	int b = (int)log2(n) + 1;
	for(int i = 0; i < n; i++) f[i] = A[i];
	for(int j = 1; j < (1 << b); j <<= 1){
		for(int i = 0; i < n; i++){
			if(i & j) f[i] += f[i ^ j];
	}
}

int main(){
	int A[100000], f[100000], n, t;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> A[j];
		sumoversubset(A, n, f);
		for(int j = 0; j < n; j++) cout << f[j] << " ";
		cout << "\n";
	}
	return 0;
}