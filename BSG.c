#include<stdio.h>

int main(){
	int n, ea, a, ec, c, eg, g, et, t, l, u, i, sol;
	char gene[500000];
	a = c = g = t = l = u = 0;
	scanf("%d", &n);
	scanf("%s", gene);
	for(i = 0; i < n; i++)
		switch(gene[i]){
			case 'A': a++;break;
			case 'C': c++;break;
			case 'G': g++;break;
			case 'T': t++;break;
		}
	ea = (a-n/4 > 0)?a-n/4:0;
	ec = (c-n/4 > 0)?c-n/4:0;
	eg = (g-n/4 > 0)?g-n/4:0;
	et = (t-n/4 > 0)?t-n/4:0;
	a = c = g = t = 0;
	sol = n;
	while(1){
		while((a < ea || c < ec || g < eg || t < et) && u < n)
			switch(gene[u++]){
				case 'A': a++;break;
				case 'C': c++;break;
				case 'G': g++;break;
				case 'T': t++;break;
			}
		while(!(a < ea || c < ec || g < eg || t < et) && l <= u)
			switch(gene[l++]){
				case 'A': a--;break;
				case 'C': c--;break;
				case 'G': g--;break;
				case 'T': t--;break;
			}
		if(u -l + 1 < sol)
			sol = u - l + 1;
		if(u >= n)
			break;
	}
	printf("%d", sol);
	return 0;
}