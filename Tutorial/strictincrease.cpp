#include <iostream>
#include <vector>

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

vector<int> a(1000000), t;

int search(int i, int j, int k){
	int mid;
	while(i < j){
		mid = (i + j) >> 1;
		if(k <= t[mid]) j = mid;
		else i = mid + 1;
	}
	return i;
}

int lis(int i, int j){
	int l;
	t.clear();
	t.PB(a[i]);
	for(int p = i + 1; p <= j; p++)
		if(a[p] < t[0]) t[0] = a[p];
		else if(a[p] > t[t.size() - 1]) t.PB(a[p]);
		else t[search(0, t.size() - 1, a[p])] = a[p];
	return t.size();
}

int main(){
	int n;
	IN n;
	for(int j = 0; j < n; j++) IN a[j];
	OUT lis(0, n - 1); newline;
	return 0;
}