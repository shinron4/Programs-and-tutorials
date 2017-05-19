#include<stdio.h>
#include<math.h>
#include<string.h>

struct tuple{
	long long int e[2], i;
};

int comp(struct tuple a, struct tuple b){
	return a.e[0] == b.e[0]? (a.e[1] <= b.e[1]? 1 : 0) : (a.e[0] <= b.e[0] ? 1 : 0);
}	

long int partition(struct tuple str[], long long int p , long long int q){
	long long int x = q, j = p , i = j - 1;
	struct tuple temp;
	for(; j < q; j++)
		if(comp(str[j], str[x])){
			i++;
			temp = str[i];
			str[i] = str[j];
			str[j] = temp;
		}
	i++;
	temp = str[i];
	str[i] = str[x];
	str[x] = temp;
	return i;
}
 
void quicksort(struct tuple str[], long long int p, long long int r){
	if(p < r){
		long long int q = partition(str, p, r);
		quicksort(str, p, q - 1);
		quicksort(str, q + 1, r);
	}
}

void suffixarray(char str[], long long int sufxary[], long long int len){
 	struct tuple a[len];
 	long long int sa[len];
	long long int i, cnt, steps = (long long int)ceil(log(len)/log(2.0)), t;
	for(i = 0; i < len; i++)
		sa[i] = str[i] - 'a';
	for(cnt = 0; cnt <= steps; cnt++){
		for(i = 0; i < len; i++){
			a[i].e[0] = sa[i];
			a[i].e[1] = i + (t = (long long int)pow(2, cnt)) < len ? sa[i + t] : -1;
			a[i].i = i;
		}
		quicksort(a, 0, len - 1);
		for(i = 0; i < len; i++)
			sa[a[i].i] = i > 0 && a[i].e[0] == a[i - 1].e[0] && a[i].e[1] == a[i - 1].e[1] ? sa[a[i - 1].i]: i;
	}
	for(i = 0; i < len; i++)
		sufxary[sa[i]] = i;
}

long long int lcparray(char a[], long long int pos[], long long int height[], long long int len){
	long long int i, rank[len], h, k;
	for(i = 0; i < len; i++)
		rank[pos[i]] = i;
	h = 0;
	for(i = 0; i < len; i++)
		if(rank[i] > 0){
			k = pos[rank[i] - 1];
			while(a[i + h] == a[k + h])
				h++;
			height[rank[i]] = h;
			if(h > 0)
				h--;
		}
	height[0] = -1;
	return rank[0];
}

int main(){
	int t, i;
	char A[100000];
	long long int pos[100000], lcp[100000], output[20], n;
	scanf("%d", &t);
	for(i = 0; i < t; i++){
		int j, k, min, similarity;
		scanf("%s", A);
		suffixarray(A, pos, n = strlen(A));
		j = lcparray(A, pos, lcp, n);
		similarity = min = n;
		for(k = j - 1; k >= 0; k--){
			if(lcp[k + 1] < min)
				min = lcp[k + 1];
			similarity += min;
		}
		min = n;
		for(k = j + 1; k < n; k++){
			if(lcp[k] < min)
				min = lcp[k];
			similarity += min;
		}
        output[i] = similarity;
    }
	for(i = 0; i < t; i++)
		printf("%lld\n", output[i]);
	return 0;
}