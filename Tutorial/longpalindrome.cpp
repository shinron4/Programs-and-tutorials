#include <iostream>
#include <cstring>

using namespace std;

int manachers(char s[], int n){
	char t[(n << 1) | 1];
	int p[(n << 1) | 1];
	for(int i = 0; i < (2 * n + 1); i++){
		if(i & 1) t[i] = s[(i - 1) >> 1];
		else t[i] = '#';
	}
	int c = 0, r = -1, rad;
	for(int i = 0; i < ((n << 1) | 1); i++){
		if(i <= r) rad = min(p[(c << 1) - i], r - i);
		else rad = 0;
		while(i + rad < ((n << 1) | 1) && i - rad >= 0 && t[i - rad] == t[i + rad]) rad++;
		rad--;
		p[i] = rad;
		if(i + rad - 1 > r){
			c = i;
			r = i + rad - 1;
		}
	}
	int m = -INT_MAX, idx;
	for(int i = 0; i < 2 * n + 1; i++){
		if(p[i] > m){
			m = p[i];
			idx = i;
		}
	}
	for(int i = idx - m; i <= idx + m; i++) if(t[i] != '#') cout << t[i];
	return (m - 1) >> 1;
}

int main(){
	int t; 
	char s[100];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> s;
		manachers(s, strlen(s));
		cout << "\n";
	}
	return 0;
}