#include <iostream>
#include <queue>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 

using namespace std;

vector< vector<int> > G(51);

int h[51], f[51][51], e[51], c[51][51], l[51];

queue<int> q;

void init(int n, int s, int t){
	for(int i = 1; i <= n; i++) h[i] = i == s ? n : 0;
	for(int j = 0; j < G[s].size(); j++){
		int v = G[s][j], w = c[s][v];
		f[s][v] = e[v] = w;
		f[v][s] = -f[s][v];
		e[s] -= w;
		c[s][v] -= f[s][v];
		c[v][s] -= f[v][s];
		if(!l[v] && v != t) l[v] = (q.push(v), 1); 
	}
}

void push(int u, int v){
	int w = c[u][v], t = e[u] < w ? e[u] : w;
	f[u][v] += t;
	f[v][u] = -f[u][v];
	e[u] -= t;
	e[v] += t;
	c[u][v] -= f[u][v];
	c[v][u] -= f[v][u];
}

int maxflow(int n, int s, int t){
	int temp, u;
	while(!q.empty()){
		u = q.front();
		//OUT u; space; OUT e[u]; newline;
		temp = 2 * n;
		for(int j = 0; j < G[u].size() && e[u] > 0; j++){
			int v = G[u][j], w = c[u][v];
			if(w > 0){
				if(h[v] < h[u]){
					push(u, v);
					if(!l[v] && v != s && v != t) l[v] = (q.push(v), 1);
				}
				else temp = h[v] < temp ? h[v] : temp;
			}
		}
		if(e[u]) h[u] = temp + 1;
		else l[u] = (q.pop(), 0);
	}
	return e[t];
}

int main(){
	int n, m, u, v, w;
	IN n; IN m;
	for(int i = 0; i < m; i++){
		IN u; IN v; IN w;
		G[u].PB(v);
		G[v].PB(u);
		c[u][v] = w;
	}
	init(n, 1, n);
	OUT maxflow(n, 1, n); newline;
	return 0;
}