#include <iostream>
#include <cstring>

using namespace std;

int manachers(char s[], int n){
	char t[(n << 1) | 1];
	int p[(n << 1) | 1];
	n = (n << 1) | 1; 
	for(int i = 0; i < n; i++){
		if(i & 1) t[i] = s[(i - 1) >> 1];
		else t[i] = '#';
	}
	int c = 0, r = -1, x;
	for(int i = 0; i < n; i++){
		if(i <= r) x = min(p[2 * c - i], r - i);
		else x = 0;
		while(i - x >= 0 && i + x < n && t[i + x] == t[i - x]) x++;
		x--;
		p[i] = x;
		if(i + x - 1 > r){
			r = i + x - 1;
			c = i;
		} 
	}
	int ma = -INT_MAX, j;
	for(int i = 0; i < n; i++){
		if(p[i] > ma){
			ma = p[i];
			j = i;
		}
	}
	for(int i = j - ma; i <= j + ma; i++) if(t[i] != '#') cout << t[i];
	cout << "\n";
	return ma;
}

int main(){
	int t; 
	char s[1000];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> s;
		cout << manachers(s, strlen(s));
	}
	return 0;
}