#include<iostream>
#include <stack>
#include <climits>

using namespace std;

int histogram(int A[], int n){
	int l[n + 2], r[n + 2], f[n + 2];
	for(int i = 0; i < n; i++) f[i + 1] = A[i];
	f[0] = f[n + 1] = 0;
	l[1] = 0;
	r[n] = n + 1;
	stack<int> s;
	s.push(0);
	for(int i = 1; i <= n + 1; i++){
		while(f[s.top()] > f[i]){
			r[s.top()] = i;
			s.pop();
		}
		if(f[s.top()] == f[i]) l[i] = l[s.top()];
		else l[i] = s.top();
		s.push(i);
	}
	int ma = -INT_MAX;
	for(int i = 1; i <= n; i++){
		ma = max(f[i] * (r[i] - l[i] - 1), ma);
	}
	return ma;
}

int main(){
	int t, n, a[1000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> a[j];
		cout << histogram(a, n) << "\n";	
	}
	return 0;
}