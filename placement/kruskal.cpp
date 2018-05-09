#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
int ds[1001];

void makeset(int n){
    for(int i = 1; i <= n; i++) ds[i] = -1;
}

int find(int n, int &x){
    if(x < 1 || x > n) return x = -1;
    while(ds[x] > 0) x = ds[x];
    return -ds[x];
}

bool unin(int n, int x, int y){
    int sx = find(n, x), sy = find(n, y);
    if(x > 0 && y > 0 && x != y){
        if(sx > sy) swap(x, y);
        ds[y] += ds[x];
        ds[x] = y;
        return true;
    }
    return false;
}
*/

void makeset(int ds[], int n){
	for(int i = 0; i < n; i++) ds[i] = -1;
}

int find(int ds[], int x, int &r){
	while(ds[x] > 0) x = ds[x];
	r = x;
	return -ds[x];
}

void unin(int ds[], int x, int y){
	int rx, sx, ry, sy;
	sx = find(ds, x, rx);
	sy = find(ds, y, ry);
	if(rx != ry){
		if(sx > sy) swap(rx, ry);
		ds[ry] += ds[rx];
		ds[rx] = ry;
	}
}

struct edge{
	int s, d, w;
};

struct COMP{
	bool operator()(struct edge &a, struct edge &b){
		return a.w < b.w;
	}
} compare;

int kruskal(vector<struct edge> &el, int n){
	int ds[n], sum = 0;
	makeset(ds, n);
	sort(el.begin(), el.end(), compare);
	for(auto it = el.begin(); it != el.end(); it++){
		struct edge e = *it;
		int rs, rd;
		find(ds, e.s, rs);
		find(ds, e.d, rd);
		if(rs != rd){
			cout << e.s << " " << e.d << "\n";
			sum += e.w;
			unin(ds, e.s, e.d);
		}
	}
	return sum;
}

int main(){
	int n, m;
	vector<struct edge> el;
	cin >> n >> m;
	for(int j = 0; j < m; j++){
		struct edge e;
		cin >> e.s >> e.d >> e.w;
		el.push_back(e);
	}
	int s = kruskal(el, n);
	cout << "size : " << s << "\n";
	return 0;
}