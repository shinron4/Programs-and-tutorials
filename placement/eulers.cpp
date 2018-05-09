#include <iostream>
#include <stack>
#include <vector>

#define MAX 1000

using namespace std;

vector< vector<int> >  G(MAX);

int tour(vector< vector<int> > & G, int n){
	int indeg[n], outdeg[n], e[n];
	for(int i = 0; i < n; i++){
		outdeg[i] = G[i].size();
		e[i] = indeg[i] = 0;
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < G[i].size(); j++){
			indeg[G[i][j]]++;
		}
	}
	for(int i = 0; i < n; i++) if(indeg[i] != outdeg[i]) return -1;
	stack<int> s;
	s.push(0);
	while(!s.empty()){
		int u = s.top(), v;
		if(e[u] == G[u].size()){
			cout << u << " ";
			s.pop();
		}
		else{
			v = G[u][e[u]++];
			while(v != u){
				s.push(v);
				v = G[v][e[v]++];
			}
			cout << u << " ";
		}
	}
	return 0;
}

int main(){
	int t, n, m;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> m;
		for(int j = 0; j < m; j++){
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
		}
		if(tour(G, n) < 0) cout << "not found\n";
		for(int j = 0; j < n; j++) G[j].clear();
	}
	return 0;
}