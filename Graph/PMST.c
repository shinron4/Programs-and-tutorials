#include<stdio.h>
#define MAXID 10000								//Maximum id of an object
#define MAXOBJ 10000							//Maximum number of objects

long int graph[3000][3000];
int buildPQ(int, long int []);
int update(int, int, long int []);
int enqueue(int, int, long int []);
int dequeue(long int []);

long int mst(int n, int s){
	int color[n], u, v, cost = 0;
	long int d[n];
	for(u = 0; u < n; u++){
		d[u] = 200000;
		color[u] = 0;
	}
	d[s] = 0;
	buildPQ(n, d);
	while((u = dequeue(d)) != -1){
		color[u] = 1;
		for(v = 0; v < n; v++)
			if(graph[u][v] != -1 && color[v] == 0 && graph[u][v] < d[v])
				update(v, graph[u][v], d);
	}
	for(u = 0; u < n; u++)
		cost += d[u];
	return cost;
}

int main(){
	int n, m, u, v, s, i;
	long int w;
	scanf("%d%d", &n, &m);
	for(u = 0; u < n; u++)
		for(v = 0; v < n; v++)
			graph[u][v] = -1;
	for(i = 0; i < m; i++){
		scanf("%d%d%ld", &u, &v, &w);
		u--, v--;
		if(graph[u][v] == -1)
			graph[u][v] = graph[v][u] = w;
		else
			graph[u][v] = graph[v][u] = (graph[u][v] <= w ? graph[u][u] : w);
	}
	printf("%ld", mst(n, 0));
	return 0;
}

int Q[MAXOBJ], IQ[MAXID], size;

void minheapify(long int key[], int i){
	int l = 2 * i + 1, r = 2 * i + 2, min = i, temp;
	if(l < size && key[Q[l]] < key[Q[i]])
		min = l;
	if(r < size && key[Q[r]] < key[Q[min]])
		min = r;
	if(min != i){
		temp = IQ[Q[i]];
		IQ[Q[i]] = IQ[Q[min]];
		IQ[Q[min]] = temp;
		temp = Q[i];
		Q[i] = Q[min];
		Q[min] = temp;
		minheapify(key, min);
	}
}

void maxheapify(long int key[], int i){
	int l = 2 * i + 1, r = 2 * i + 2, max = i, temp;
	if(l < size && key[Q[l]] > key[Q[i]])
		max = l;
	if(r < size && key[Q[r]] > key[Q[max]])
		max = r;
	if(max != i){
		temp = IQ[Q[i]];
		IQ[Q[i]] = IQ[Q[max]];
		IQ[Q[max]] = temp;
		temp = Q[i];
		Q[i] = Q[max];
		Q[max] = temp;
		maxheapify(key, max);
	}
}

int buildPQ(int len, long int key[]){
	int i;
	if((size = len) > MAXOBJ)
		return -1;
	for(i = 0;i < len; i++){
		Q[i] = i;
		IQ[i] = i;
	}
	for(i = size/2 - 1; i >= 0; i--)
		minheapify(key, i);					//maxheapify when building max priority queue
	return 0;
}

int update(int i, int k, long int key[]){
	int x = IQ[i], y = (x + 1)/2 - 1;
	if(k < key[i]){								//k > key[i] when building max priority queue
		key[i] = k;
		while(y >= 0 && k < key[Q[y]]){
			IQ[Q[y]] = x;
			Q[x] = Q[y];
			x = y;
			y = (x + 1)/2 - 1;
		}
		IQ[i] = x;
		Q[x] = i;
		return 0;
	}
	return -1;
}

int enqueue(int i, int k, long int key[]){
	if(size == MAXOBJ)
		return -1;
	key[i] = 200000;							// -200000 when building max priority queue
	IQ[i] = size;
	Q[size] = i;
	size++;
	return update(i, k, key);
}

int dequeue(long int key[]){
	int x = Q[0];
	if(size == 0)
		return -1;
	Q[0] = Q[size - 1];
	IQ[Q[--size]] = 0;
	minheapify(key, 0);						//maxheapify when building max priority queue
	return x;
}