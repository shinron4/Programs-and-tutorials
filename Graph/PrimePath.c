#include<stdio.h>
#include<math.h>

char primes[10000], color[9000];
int d[9000], enqueue(int), dequeue(void);
void init(void);

void primenumbers(int p){
	int i = 2, k;
	while(i * i <= p){
		primes[i * i] = '1';
		k = i + 1;
		while(k * i <= p){
			primes[k * i] = '1';
			k++;
		}
		i++;
		while(i <= p && primes[i] == '1')
			i++;
	}
}

int bfs(int s, int de){
	int i, j, x, y, u, v;
	extern int Q[10000];
	init();
	for(i = 0; i < 9000; i++){
		color[i] = 'w';
		d[i] = 10000;
	}
	d[s - 1000] = 0;
	color[s - 1000] = 'r';
	enqueue(s);
	while((u = dequeue()) != -1 && u != de){
		color[u - 1000] = 'b';
		for(i = 1; i <= 4; i++){
			x = u / (int)pow(10, i);
			y = u % (int)pow(10, i - 1);
			for(j = 0; j < 10; j++){
				if(i == 4 && j == 0)
					continue;
				v = x * (int)pow(10, i) + j * (int)pow(10, i - 1) + y;
				if(v != u && primes[v] != '1' && color[v - 1000] == 'w'){
					d[v - 1000] = d[u - 1000] + 1;
					color[v - 1000] = 'r';
					enqueue(v);
				}
			}
		}
	}
	if(u == de)
		return d[u - 1000];
	else
		return -1;
}

int main(){
	int t, i, s, d, p;
	primenumbers(9999);
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		scanf("%d%d", &s, &d);
		if((p = bfs(s, d)) == -1)
			printf("Impossible\n");
		else
			printf("%d\n", p);
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
int dequeue(void){
	int x;
	if(head == tail)
		return -1;
	x = Q[head++];
	if(head == tail)
		head = tail = 0;
	return x;
}

void init(void){
	head = tail = 0;
}
