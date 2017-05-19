#include <set>
#include <iostream>

using namespace std;

int main(){

	set<int> T;

	int n, x, i;

	cin >> n;

	for(i = 0; i < n; i++){
		cin >> x;
		T.insert(x);
	}

	for(set<int>:: iterator it = T.begin(); it != T.end(); it++)
		cout << *it << " ";

	if (T.find(10) != T.end())
		cout << 1;
	cout << "\n";
	return 0;
}