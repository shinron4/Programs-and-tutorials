#include <iostream>
#include <string>

using namespace std;

int bsearch(int a[], int i, int j, int x){
	int mid;
	while(i < j){
		mid = (i + j) >> 1;
		if(x <= a[mid]) j = mid;
		else i = mid + 1;
	}
	return i;
}

bool nextperm(int a[], int n){
	int j = n - 1;
	while(j - 1 >= 0 && a[j - 1] >= a[j]) j--;
	if(j == 0) return false;
	for(int i = 0; i < (n - j) >> 1; i++) swap(a[i + j], a[n - 1 - i]);
	int i = bsearch(a, j, n - 1, a[j - 1]);
	while(a[i] == a[j - 1]) i++;
	swap(a[i], a[j - 1]);
	return true;
}

int main(){
	int t, a[100];
	string s;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> s;
		for(int j = 0; j < s.length(); j++) a[j] = s[j] - '0';
		if(!nextperm(a, s.length())) cout << "not possible";
		else for(int j = 0; j < s.length(); j++) cout << a[j];
		cout << "\n";
	}
	return 0;
}