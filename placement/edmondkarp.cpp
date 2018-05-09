#include <iostream>
#include <vector>
#include <queue>

#define MAX 1000

using namespace std;

struct neighbour{
	int t, s;
	int c, f;
};

vector< vector<struct neighbour> > G(MAX + 1);

void addedge(int u, int v, int w){
	struct neighbour t;
	int lu = G[u].size(), lv = G[v].size();
	t.t = v;
	t.s = lv;
	t.c = w;
	t.f = 0;
	G[u].push_back(t);
	t.t = u;
	t.s = lu;
	t.c = 0;
	G[v].push_back(t);
}

void cleargraph(int n){
	for(int i = 1; i <= n; i++) G[i].clear();
}

int d[MAX + 1], ptr[MAX + 1];

bool reachable(int n, int s, int t){
	for(int i = 1; i <= n; i++) d[i] = INT_MAX;
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(int i = 0; i < G[u].size(); i++){
			int v = G[u][i].t;
			if(G[u][i].f < G[u][i].c && d[v] == INT_MAX){
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	return d[t] != INT_MAX;
}

int pushflow(int u, int t, int f){
	int push = 0;
	if(f == 0 || u == t) return f;
	for(int &i = ptr[u]; i < G[u].size(); i++){
		int v = G[u][i].t, j = G[u][i].s;
		if(d[v] == d[u] + 1 && G[u][i].f < G[u][i].c){
			push = pushflow(v, t, min(f, G[u][i].c - G[u][i].f));
			if(push){
				G[u][i].f += push;
				G[v][j].f = -G[u][i].f;
				return push;
			}
		}
	}
	return 0;
}

int maxflow(int n, int s, int t){
	int f = 0;
	while(reachable(n, s, t)){
		for(int i = 1; i <= n; i++) ptr[i] = 0;
		f += pushflow(s, t, INT_MAX);
	}
	return f;
}

int main(){
	int t, n, m;
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n >> m;
		for(int j = 0; j < m; j++){
			int u, v, w;
			cin >> u >> v >> w;
			addedge(u, v, w);
		}
		cout << maxflow(n, 1, n) << "\n";
		cleargraph(n);
	}
	return 0;
}