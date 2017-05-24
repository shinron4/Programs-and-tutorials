#include <iostream>
#include <cmath> 
#include <vector>
#include <cstring>
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
#define CHILD_SIZE 26

using namespace std;

struct tnode{
	int w, p;
	struct tnode *c[CHILD_SIZE];
	tnode(){
		w = p = 0;
		for(int i = 0; i < CHILD_SIZE; i++) c[i] = 0;
	}
};

void insert(struct tnode *n, char w[], int l){
	struct tnode *temp = n;
	for(int i = 0; i < l; i++){	
		temp->p += 1;
		OUT w[i]; space;
		if(!temp->c[w[i] - 'a']) temp->c[w[i] - 'a'] = new tnode();
		temp = temp->c[w[i] - 'a'];
	}
	temp->w += 1;
}

int countWord(struct tnode *n, char w[], int l){
	struct tnode *temp = n;
	for(int i = 0; i < l; i++){
		if(!temp->c[w[i] - 'a']) return 0;
		temp = temp->c[w[i] - 'a'];
	}
	return temp->w;
}

int countPrefix(struct tnode *n, char w[], int l){
	struct tnode *temp = n;
	for(int i = 0; i < l; i++){
		if(!temp->c[w[i] - 'a']) return 0;
		temp = temp->c[w[i] - 'a'];
	}
	return temp->p;
}

int main(){
	int n;
	char a[100], b[] = "allow";
	struct tnode *t = new tnode();
	IN n;
	for(int i = 0; i < n; i++){
		IN a;
		insert(t, a, strlen(a)); newline;
	}
	OUT countWord(t, b, 5); newline;
	return 0;
}