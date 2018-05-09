#include <iostream>

#define MAX 1000000
using namespace std;

template<typename T>
class stack{
private:
	int s;
	T a[MAX];
public:
	stack() {s = -1;}
	int size() {return s + 1;}
	bool empty() {return size() == 0;}
	bool full() {return size() == MAX;}
	T top() { return a[s];}
	void push(T x) {a[++s] = x;}
	T pop(){ return a[s--];}
};


int main(){
	return 0;
}