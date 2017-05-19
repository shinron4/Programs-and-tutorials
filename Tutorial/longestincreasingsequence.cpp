#include <iostream>
#include <cmath> 
#include <vector>
#include <algorithm>

#define MP make_pair
#define PB push_back
#define F first 
#define S second
#define newline cout << "\n"
#define space cout << " "
#define IN cin >> 
#define OUT cout << 
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;

vector < pair< int, pair <int ,int> > > a(100000);

pair<int, int> lis(int i, int j){
	pair<int, int> longest;
	a[i].S.F = 1;
	a[i].S.S = -1;
	longest.F = 1;
	longest.S = 0;
	for(int p = i + 1; p <= j; p++){
		a[p].S.F = 1;
		a[p].S.S = -1;
		for(int q = p - 1; q >= 0; q--){
			if(a[p].F > a[q].F){
				if(a[q].S.F + 1 > a[p].S.F){
					a[p].S.F = a[q].S.F + 1;
					a[p].S.S = q;
 				}
			}
		}
		if(a[p].S.F > longest.F){
			longest.F = a[p].S.F;	
			longest.S = p;
		}
	}
	return longest;
}

int main(){
	int n, x;
	pair<int, int> l;
	IN n;
	for(int i = 0; i < n; i++){
		IN a[i].F;
		a[i].S.F = a[i].S.S = 0;
	}
	l = lis(0, n - 1);
	OUT l.F; newline;
	return 0;
}