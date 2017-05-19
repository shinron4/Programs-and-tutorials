#include <vector>
#include <iostream>

using namespace std;

void inputVector(vector< pair<int,int> > & arr, int n){
	int i, x;
	pair <int, int> p;
	for(i = 0; i < n; i++){
		cin >> p.first >> p.second;
		arr.push_back(p);
	}	
}

void outputVector(const vector< pair<int,int> > & arr){
	int n = arr.size(), i;
	for(vector< pair<int, int> >::const_iterator it = arr.begin(); it != arr.end(); it++ )
		cout << it->first << " " << it->second;
	cout << "\n";
}

int main(){

	vector< pair<int, int> > arr;

	int n;

	cin >> n;
	inputVector(arr, n);
	cout << arr.size() << " " << arr.empty() << " " << "\n";
	outputVector(arr);
	return 0;
}