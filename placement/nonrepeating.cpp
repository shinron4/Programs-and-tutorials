#include <iostream>
#include <queue>

using namespace std;

class compare{
public:
	bool operator()(pair<char, int> a, pair<char, int> b){
		return a.second > b.second;
	}
};

int main(){
	int t, n, al[26];
	cin >> t;
	for(int i = 0; i < t; i++){
		for(int j = 0; j < 26; j++) al[j] = 0;
		priority_queue< pair<char, int>, vector< pair<char, int> >, compare > q;
		cin >> n;
		for(int j = 0; j < n; j++){
			char a;
			cin >> a;
			if(al[a - 'a'] == 0){
				al[a - 'a'] = 1;
				q.push(make_pair(a, j));
			}
			else al[a - 'a']++;
			while(!q.empty() && al[q.top().first - 'a'] > 1) q.pop();
			if(!q.empty()) cout << q.top().first << " ";
			else cout << -1 << " ";
		}
		cout << "\n";
	}
	return 0;
}