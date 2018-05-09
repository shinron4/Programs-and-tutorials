#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void sumequalk(int a[], int n, int sum){
	int mask[12][2], j = 0, m = 0;
	bool f = false;
	mask[m][0] = j;
	for(int i = 1; i < n; i++){
		if(a[i] != a[j]){
			mask[m][1] = i - 1;
			mask[++m][0] = i;
			j = i;
		}
	}
	mask[m++][1] = n - 1;
	for(int s = 0; s < 1 << n; s++){
		int shift = 0, i = 0, x = 0, y = 0;
		for(int j = m - 1; j >= 0; j--){
			int sb = 0;
			for(int k = mask[j][1]; k >= mask[j][0]; k--){
				if(s & (1 << k)){
					x += a[k];
					sb++;
				}
			}
			i <<= shift;
			i |= ((1 << sb) - 1);
			if(j > 0) shift = mask[j - 1][1] - mask[j - 1][0] + 1;
			y += sb;
		}
		if(i >= s && x == sum){
			f = true;
			cout << "(";
			for(int k = 0; k < n; k++){
				if(s & (1 << k)){
					cout << a[k];
					if(y > 1) cout << " ";
					y--;
				}
			}
			cout << ")";
		}
	}
	if(!f) cout << "Empty";
}

int main(){
	int t, n, sum, a[12];
	cin >> t;
	for(int i = 0; i < t; i++){
		cin >> n;
		for(int j = 0; j < n; j++) cin >> a[j];
		cin >> sum;
		sort(a, a + n);
		sumequalk(a, n, sum);
		cout << "\n";
	}
	return 0;
}