#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int a[1048576], f[1048576];

void sumoversubset(int n){
	int b = (int) log2(n) + 1;
	for(int i = 0; i <= n; i++) f[i] = a[i];
	for(int i = 1; i < (1 << b); i <<= 1){
		for(int j = 0; j <= n; j++){
			if(j & i) f[j] += f[j ^ i];
		}
	}
}

int main(){
	int test, n, t[100000], ma, b;
	cin >> test;
	for(int i = 0; i < test; i++){
		cin >> n;
		ma = -INT_MAX;
		for(int j = 0; j < n; j++){
			cin >> t[j];
			ma = max(ma, t[j]);
			a[t[j]]++;
		}
		b = (int)log2(ma) + 1;
		sumoversubset((1 << b) - 1);
		int sum = 0;
		for(int j = 0; j < n; j++){
			if(a[t[j]] > 0){
				sum += f[t[j] ^ ((1 << b) - 1)];
			}
		}
		for(int j = 0; j <= ((1 << b) - 1); j++) a[j] = 0;
		cout << sum << "\n";
	}
	return 0;
}