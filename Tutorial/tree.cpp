#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

struct node{
	int k;
	struct node *l, *r;
} *t;

struct node * create(int k){
	struct node *n;
	n = (struct node *) malloc(sizeof(struct node));
	n->k = k;
	n->l = n->r = NULL;
	return n;
}

void preorder(struct node * r){
	stack< pair<struct node *, int> > s;
	s.push(make_pair(r, 1));
	while(!s.empty()){
		struct node *t = s.top().first;
		if(t == NULL || s.top().second == 4) s.pop();
		else{
			switch(s.top().second){
				case 1:
					s.top().second = 2;
					cout << t->k << " ";
					break;
				case 2:
					s.top().second = 3;
					s.push(make_pair(t->l, 1));
					break;
				case 3:
					s.top().second = 4;
					s.push(make_pair(t->r, 1));
					break;
			}
		}
	}
}

void inorder(struct node *r){
	stack< pair<struct node *, int> >s;
	s.push(make_pair(r, 1));
	while(!s.empty()){
		struct node *t = s.top().first;
		if(t == NULL || s.top().second == 4) s.pop();
		else{
			switch(s.top().second){
				case 1:
					s.top().second = 2;
					s.push(make_pair(t->l , 1));
					break;
				case 2:
					cout << t->k << " ";
					s.top().second = 3;
					break;
				case 3:
					s.top().second = 4;
					s.push(make_pair(t->r, 1));
					break;
			}
		}
	}
}

void postorder(struct node * r){
	stack< pair<struct node *, int> > s;
	s.push(make_pair(r, 1));
	while(!s.empty()){
		struct node *t = s.top().first;
		if(t == NULL || s.top().second == 4) s.pop();
		else{
			switch(s.top().second){
				case 1:
					s.top().second = 2;
					s.push(make_pair(t->l, 1));
					break;
				case 2:
					s.top().second = 3;
					s.push(make_pair(t->r, 1));
					break;
				case 3:
					s.top().second = 4;
					cout << t->k << " ";
					break;
			}
		}
	}
}
int main(){
	t = create(1);
	t->l = create(2);
	t->r = create(3); 
	inorder(t);
	cout << "\n";
	preorder(t);
	cout << "\n";
	postorder(t);
	return 0;
}