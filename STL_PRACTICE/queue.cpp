#include <iostream>
#include <queue>

using namespace std;

pair <int, int> p;

int main (){

	queue< pair<int, int> > Q;

	int n = 0, x;

	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> p.first >> p.second;
		Q.push(p);
	}

	cout << "Front : " << Q.front().first << " " << Q.front().second << "\n";
	cout << "Back : " << Q.back().first << " " << Q.back().second << "\n";

 	while(!Q.empty()){
		cout << "Front : " << Q.front().first << " " << Q.front().second << "\n";
		Q.pop();
	}
	return 0;
}