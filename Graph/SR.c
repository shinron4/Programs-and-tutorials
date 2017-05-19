#include<stdio.h>

int graph[1000][1000], distance[1000], enqueue(int), dequeue();

void bfs(int n, int s){
	int color[1000], u, v;
	for(u = 0; u < n; u++){
		color[u] = 0;
		distance[u] = 10000;
	}
	color[s] = 1;
	distance[s] = 0;
	enqueue(s);
	while((u = dequeue()) != -1){
		color[u] = 2;
		for(v = 0; v < n; v++)
			if(graph[u][v] == 1 && color[v] == 0){
				color[v] = 1;
				distance[v] = distance[u] + 1;
				enqueue(v);
			}
	}
}

int main(){
	int q, n, m, u, v, s, i, j, k;
	scanf("%d", &q);
	for(i = 0; i < q; i++){
		scanf("%d%d", &n, &m);
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				graph[j][k] = 10000;
		for(j = 0; j < m; j++){
			scanf("%d%d", &u, &v);
			graph[u - 1][v - 1] = graph[v - 1][u - 1] = 1;
		}
		scanf("%d", &s);
		bfs(n, s - 1);
		for(j = 0; j < n; j++)
			if(j != s - 1){
				if(distance[j] < 10000)
					printf("%d ", 6 * distance[j]);
				else
					printf("%d ", -1);
			}
		printf("\n");
	}
	return 0;
}

int Q[10000], head, tail;
int enqueue(int ele){
	if(tail - head == 10000)
		return -1;
	Q[tail++] = ele;
	return 0;
}
int dequeue(){
	int x;
	if(head == tail)
		return -1;
	x = Q[head++];
	if(head == tail)
		head = tail = 0;
	return x;
}
