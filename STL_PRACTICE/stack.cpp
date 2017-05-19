#include <stack>
#include <iostream>

using namespace std;

pair<int, int> point;

int main(){

	stack < pair<int, int> > S;
	int n, x;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> point.first >> point.second;
		S.push(point);
	}

	while(!S.empty()){
		cout << S.top().first << " " << S.top().second;
		S.pop();
	}
	cout << "\n";
	return 0;
}