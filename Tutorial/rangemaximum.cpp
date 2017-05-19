#include <iostream>
#include <vector>
#include <algorithm>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

int a[100005];

int max(int a, int b){
	return a > b ? a : b;
}

void build(int n){
	for(int i = n - 1; i >= 1; i -= 1) a[i] = max(a[i << 1], a[i << 1 | 1]);
}

int query(int l, int r, int n){
	int m1, m2;
	m1 = m2 = -16000;
	for(l += n - 1, r += n - 1; l < r; l >>= 1, r >>= 1){
		//OUT l; space; OUT r; newline;
		if(l & 1) m1 = max(m1, a[l++]);
		if(r & 1) m2 = max(m2, a[--r]);
		//OUT m1; space; OUT m2; newline;
	}
	return max(m1, m2);
}

int main (){
	fastIO
	int n, m, l, r;
	IN n;
	for(int i = 1; i <= n; i++) IN a[i + n - 1];
	build(n);
	IN m;
	for(int i = 0; i < m; i++){
		IN l; IN r;
		OUT query(l, r + 1, n); newline;
	}
	return 0;
}