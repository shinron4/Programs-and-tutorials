#include <iostream>
#include <string>
#include <cstdlib>
#include <queue>
#include <vector>

using namespace std;

struct trie{
	int word;
	struct trie *child[26], *p;
};

int insert(struct trie * r, string s, int i){
	int n = s.length();
	for(int i = 0; i < n; i++){
		if(r->child[s[i] - 'a'] == NULL){
			r->child[s[i] - 'a'] = (struct trie *)malloc(sizeof(struct trie));
			r->child[s[i] - 'a']->word = -1;
			for(int j = 0; j < 26; j++) r->child[s[i] - 'a']->child[j] = NULL;
			r->child[s[i] - 'a']->p = NULL;
		}
		r = r->child[s[i] - 'a'];
	}
	return r->word = i;
}

int prefix(struct trie * r){
	if(r == NULL) return -1;
	queue<struct trie *> q;
	r->p = r;
	for(int i = 0; i < 26; i++){
		if(r->child[i] != NULL){
			r->child[i]->p = r;
			q.push(r->child[i]);
		}
	}
	while(!q.empty()){
		struct trie * t = q.front();
		q.pop();
		for(int i = 0; i < 26; i++){
			if(t->child[i] != NULL){
				struct trie * u = t->p;
				while(u != r && u->child[i] == NULL) u = u->p;
				if(u->child[i] != NULL) u = u->child[i];
				t->child[i]->p = u;
				q.push(t->child[i]);
			}
		}
	}
	return 0; 
}

void matcher(vector<string> dict, string text){
	struct trie * r = (struct trie *)malloc(sizeof(struct trie)), *t;
	r->word = -1;
	for(int i = 0; i < 26; i++) r->child[i] = NULL;
	r->p = NULL;
	for(int i = 0; i < dict.size(); i++) insert(r, dict[i], i);
	prefix(r);
	t = r;
	for(int i = 0; i < text.size(); i++){
		while(t != r && t->child[text[i] - 'a'] == NULL) t = t->p;
		if(t->child[text[i] - 'a'] != NULL) t = t->child[text[i] - 'a'];
		if(t->word != -1) cout << dict[t->word] << "\n";
	}
}

int main(){
	int n;
	string s, t;
	vector<string> dict;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> s;
		dict.push_back(s);
	}
	cin >> t;
	matcher(dict, t);
	return 0;
}