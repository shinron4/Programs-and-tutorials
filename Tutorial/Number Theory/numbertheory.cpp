#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long int

//primes int range[1, ...., MAX]

#define MAX 1000000 

bool p[MAX - 1];
vector<int> primes;

void sieve(){
	int u = (int)sqrt(MAX);
	for(int i = 2; i <= u; i++){
		if(!p[i - 2]){
			for(int j = i << 1; j <= MAX; j += i){
				p[j - 2] = true;
				primes.push_back(j);
			}
		}
	}
}

//Greatest common divisior gcd(x, y)

ll gcd(ll x, ll y){
	if(x < y) swap(x, y);
	while(y > 0){
		ll r = x % y;
		x = y;
		y = r;
	}
	return x;
}

//Inverse Computation a * a' = 1 (mod n)
//a' is the inverse of a in (mod n)
//gcd(a, n) = 1
//n > 1

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

// fast modular exponentiation a ^ m (mod n)

ll fastmod(ll a, ll m, ll n){
	int b = (int)log2(m) + 1;
	ll z = 1;
	for(int j = b - 1; j >= 0; j--){
		z = (z * z) % n;
		if(m & (1 << j)) z = (z * a) % n;
	}
	return z;
}

//Primality testing miller-rabin algorithm.
//Monte carlo no biased. 
//Error probability is (1 / 4)
//Run millerrabin for 10 times atleast

bool millerrabin(ll n){
	ll m = n - 1, a, t;
	int k = 0;
	while(!(m & 1)){
		m >>= 1;
		k++;
	}
	a = rand() % (n - 1) + 1;
	t = fastmod(a, m, n);
	if(t == 1) return true;
	for(int j = 0; j < k; j++){
		if(t == n - 1) return true;
		else t = (t * t) % n;
	}
	return false;
}

bool detprime(ll n){
	bool f = true;
	for(int j = 0; j < 10; j++){
		f = f & millerrabin(n);
	}
	return f;
}

//Integer factorisation pollard-rho 
//Returns one of the factors of the number n if n is composite else fails.
//If fails use different initial values.

ll pollardrho(ll n){
	ll x, y, p = 1;
	x = y = rand() % (n - 1) + 1;
	while(p == 1){
		x = (x * x + 1) % n;
		y = (y * y + 1) % n;
		y = (y * y + 1) % n;
		p = gcd(abs(x - y), n);
	}
	return p;
}

ll factor(ll n){
	if(detprime(n)) return n;
	srand(time(NULL));
	ll f;
	do{
		f = pollardrho(n);
	} while(f == n);
	return f;
}

