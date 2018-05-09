#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> findRedundantDirectedConnection(vector< vector<int> >& edges){
	int n = edges.size(), color[n + 1], p[n + 1], f[n + 1];
	vector< vector< pair<int, int> > > g(n + 1);
	for(int i = 1; i <= n; i++) color[i] = f[i] = 0;
	for(int i = 0; i < n; i++){
		g[edges[i][0]].push_back(make_pair(edges[i][1], i));
		f[edges[i][1]]++;
	}
	int r = -1, x;
	for(int i = 1; i <= n; i++){
		if(f[i] > 1) r = i;
		else if(f[i] == 0) x = i;
	}
	stack< pair<int, vector< pair<int, int> >::iterator> >s;
	vector<int> cycle;
	if(r > 0){
		s.push(make_pair(x, g[x].begin()));
		color[x] = 1;
		while(!s.empty()){
			int u = s.top().first;
			auto j = s.top().second;
			while(j != g[u].end() && color[(*j).first] != 0){
				if(color[(*j).first] == 1){
					vector<int> temp;
					temp.push_back(u);
					temp.push_back((*j).first);
					return temp;
				}
				j++;
			}
			if(j != g[u].end()){
				color[(*j).first] = 1;
				auto k = j;
				s.top().second = ++k;
				s.push(make_pair((*j).first, g[(*j).first].begin()));
			}
			else{
				color[u] = 2;
				s.pop();
			}
		}
		vector<int> temp(2);
		int l = -1, li, m = -1, mi, ma = -1;
		for(int i = 1; i <= n; i++){
			for(auto it = g[i].begin(); it != g[i].end(); it++){
				if((*it).first == r){
					if(l < 0){
						l = i;
						li = (*it).second;
					}
					else{
						m = i;
						mi = (*it).second;
					}
					break;
				}
			}
		}
		if(li > mi){
			temp[0] = l;
			temp[1] = r;
		}
		else{
			temp[0] = m;
			temp[1] = r;
		}
		return temp;
	}
	else{
		for(int i = 1; i <= n; i++){
			if(color[i] == 0){
				s.push(make_pair(i, g[i].begin()));
				color[i] = 1;
				while(!s.empty()){
					int u = s.top().first;
					auto j = s.top().second;
					int f = false;
					while(j != g[u].end() && color[(*j).first] != 0){
						if(color[(*j).first] == 1){
							cycle.push_back((*j).first);
							while(s.top().first != (*j).first){
								cycle.push_back(s.top().first);
								s.pop();
							}
							cycle.push_back((*j).first);
							f = true;
							break;
						}
						j++;
					}
					if(f) break;
					if(j != g[u].end()){
						color[(*j).first] = 1;
						auto k = j;
						s.top().second = ++k;
						s.push(make_pair((*j).first, g[(*j).first].begin()));
					}
					else{
						color[u] = 2;
						s.pop();
					}
				}
			}
		}
		vector<int> temp(2);
		int ma = -1;
		for(int j = cycle.size() - 1; j > 0; j--){
			auto it = g[cycle[j]].begin();
			for(; it != g[cycle[j]].end(); it++){
				if((*it).first == cycle[j - 1]) break;
			}
			if((*it).second > ma){
				ma = (*it).second;
				temp[0] = cycle[j];
				temp[1] = cycle[j - 1];
			}

		}
		return temp;
	}
}

int main(){
	vector< vector<int> > e;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		vector<int> temp(2);
		cin >> temp[0] >> temp[1];
		e.push_back(temp);
	}
	vector <int> temp = findRedundantDirectedConnection(e);
	cout << temp[0] << " " << temp[1] << "\n";
}