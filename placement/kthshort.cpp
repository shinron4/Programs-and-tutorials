#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int mid(int A[], int l, int r){
	sort(A + l, A + r + 1);
	return A[(l + r) >> 1];
}

int partition(int A[], int n){
	int x = A[n - 1], j = -1;
	for(int i = 0; i < n - 1; i++){
		if(A[i] <= x){
			j++;
			swap(A[j], A[i]);
		}
	}
	j++;
	swap(A[j], A[n - 1]);
	return j;
}

int klargest(int A[], int n, int k){
	int mom;
	if(n > 1){
		int m = ceil(n / 5.0), B[m];
		for(int i = 0; i < n; i += 5){
			B[i/5] = mid(A, i, i + 4 < n ? i + 4 : n - 1);
		}
		mom = klargest(B, m, ceil(m / 2.0));
	}
	else return A[0];
	int j = 0;
	for(; j < n; j++) if(A[j] == mom) break;
	swap(A[j], A[n - 1]);
	j = partition(A, n) + 1;
	int C[max(j, n - j)];
	if(j > k){
		for(int i = 0; i < j - 1; i++) C[i] = A[i];
		return klargest(C, j - 1, k);
	}
	else if(j == k) return mom;
	else{
		for(int i = j; i < n; i++) C[i - j] = A[i];
		return klargest(C, n - j, k - j);
	}
}

int A[1000];
int main(){
	int t, n, k, x;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> k;
		for(int j = 0; j < n; j++) cin >> A[j];
		x = klargest(A, n, n - k + 1);
		int j = n;
		for(int l = n - 1; l >= 0; l--){
			if(A[l] >= x){
				j--;
				swap(A[j], A[l]);
			}
		}
		sort(A + j, A + n);
		for(int l = n - 1; l >= n - k; l--) cout << A[l] << " ";
		cout << "\n";
	}
	return 0;
}