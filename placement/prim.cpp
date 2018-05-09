#include <iostream>
#include <queue>

using namespace std;

class compare{
public:
	bool operator()(pair<int, int> &a, pair<int, int> &b){
		return a.second > b.second;
	}
};

int prim(vector< vector< pair<int, int> > > &G, int n, int s){
	bool color[n];
	int sum = 0, d[n];
	for(int i = 0; i < n; i++){
		color[i] = false;
		d[i] = INT_MAX;
	}
	priority_queue< pair<int, int>, vector< pair<int, int> >, compare > q;
	d[s] = 0;
	q.push(make_pair(s, d[0]));
	while(!q.empty()){
		int u = q.top().first, w = q.top().second;
		q.pop();
		if(color[u] == false){
			sum += w;
			color[u] = true;
			for(int j = 0; j < G[u].size(); j++){
				int v = G[u][j].first;
				if(color[v] == false && d[v] > G[u][j].second){
					d[v] = G[u][j].second;
					q.push(make_pair(v, d[v]));
				}
			}
		}
	}
	cout << "\n";
	return sum;
}

int main(){
	int n, m;
	vector< vector< pair<int, int> > > G(100);
	cin >> n >> m;
	for(int j = 0; j < m; j++){
		int x, y, w;
		cin >> x >> y >> w;
		G[x].push_back(make_pair(y, w));
		G[y].push_back(make_pair(x, w));
	}
	int s = prim(G, n, 0);
	cout << "size : " << s << "\n";
	return 0;
}