#include <iostream>
#include <vector>
#define MAX 1000000

using namespace std;

//Finds the smallest prime factor of all the numbers int range [2, ..., MAX]
//Linear time O(MAX)

int sp[MAX - 1];
vector<int> primes;

void sieve2(){
	for(int i = 2; i <= MAX; i++){
		if(sp[i - 2] == 0){
			sp[i - 2] = i;
			primes.push_back(i);
		}
		for(int j = 0; j < primes.size() && primes[j] <= i && i * primes[j] <= MAX; j++){
			sp[i * primes[j] - 2] = primes[j];
		}
	}
}

//Linear Sieve with Euler-totient function of [1, ...., MAX]

int phi[MAX - 1];

void eulerphi(){
	phi[1] = 1;
	for(int i = 2; i <= MAX; i++){
		if(sp[i - 2] == 0){
			sp[i - 2] = i;
			phi[i - 2] = i - 1;
			primes.push_back(i); 
		}
		else{
			if(sp[i - 2] == sp[i / sp[i - 2] - 2]){
				phi[i - 2] = phi[i / sp[i - 2] - 2] * sp[i - 2];
			}
			else{
				phi[i - 2] = phi[i / sp[i - 2] - 2] * (sp[i - 2] - 1);
			}
		}
		for(int j = 0; j < primes.size() && primes[j] <= i && i * primes[j] <= MAX; j++){
			sp[i * primes[j] - 2] = primes[j];
		}
	}
}



int main(){
	eulerphi();
	// for(int i = 2; i <= 100; i++) cout << sp[i - 2] << " ";
	// cout << "\n";
	for(int i = 2; i <= 100; i++) cout << phi[i - 2] << " ";
	cout << "\n";

	return 0;
}