#include <iostream>

#define MAX 1000000
#define ll long long int

using namespace std;

ll inverse(ll a, ll n){
	ll s0 = 1, s1 = 0, nu = a, de = n;
	while(nu < 0) nu += de;
	while(de > 1){
		int q = nu / de, r = nu % de, t;
		t = s0 - q * s1;
		s0 = s1;
		s1 = t;
		nu = de;
		de = r;
	}
	while(s1 < 0) s1 += n;
	return s1;
}

//nCr % p primes must be small i.e. less than 10^7.
//We will precompute and store factorials mod p. 

int lucas(ll fact[], ll n, ll r, int p){
	if(r == 0 || r == n) return 1;
	else if(r > n) return 0;
	ll tot = 1;
	while(n > 0){
		ll s, t;
		s = n % p;
		t = r % p;
		if(s >= t){
			ll temp = (fact[t] * fact[s - t]) % p;
			temp = inverse(temp, p);
			temp = (fact[s] * temp) % p;
			tot = (tot * temp) % p;
		}	
		else tot = 0;
		n /= p;
		r /= p;
	}
	return tot;
}

int main(){
	int t, q, n, r, p;
	cin >> t;
	while(t--){
		cin >> p;
		long long int fact[p];
		fact[0] = 1;
		for(int i = 1; i < p; i++) fact[i] = (fact[i - 1] * i) % p;
		cin >> q;
		while(q--){
			cin >> n >> r;
			cout << lucas(fact, n, r, p) << "\n";
		}
	}
	return 0;
}