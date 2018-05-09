#include <iostream>
#include <cstring>

using namespace std;

void prefix(char s[], int n, int p[]){
	int k;
	k = p[1] = 0;
	for(int i = 2; i <= n; i++){
		while(k > 0 && s[k + 1] != s[i]) k = p[k];
		if(s[k + 1] == s[i]) k++;
		p[i] = k;

	}
}

void matcher(char t[], char s[], int n, int m){
	int p[m + 1], k = 0;
	prefix(s, m, p);
	for(int i = 1; i <= n; i++){
		while(k > 0 && s[k + 1] != t[i]) k = p[k];
		if(s[k + 1] == t[i]) k++;
		if(k == m){
			cout << i - m + 1 << " ";
			k = p[k];
		}
	}
	cout << "\n";
}

int main(){
	int n, m, test;
	char s[1001], t[1001];
	cin >> test;
	for(int i = 0; i < test; i++){
		cin >> t >> s;
		n = strlen(t);
		m = strlen(s);
		for(int j = m - 1; j >= 0; j--) s[j + 1] = s[j];
		for(int j = n - 1; j >= 0; j--) t[j + 1] = t[j];
		matcher(t, s, n, m);
	}
	return 0;
} 