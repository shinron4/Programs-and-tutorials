#include<stdio.h>
#include<string.h>
 
int partition(int str[],int p , int q){
	int x = q, j = p , i = j - 1, temp;
	for(; j < q; j++)
		if(str[j] <= str[x]){
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
 
void quicksort(int str[], int p, int r){
	if(p < r){
		int q = partition(str, p, r);
		quicksort(str, p, q - 1);
		quicksort(str, q + 1, r);
	}
}
 
int countdistinct(int str[], int len){
	int i , count = 0;
	for(i = 1; i < len; i++)
		if(str[i] != str[i - 1])
			count++;
	return count + 1;
}

int main(){
		char str[100000];
		int letters[26], *t, n, i, c,f, s;
		f = s = 0;
		scanf("%s", str);
		n = strlen(str);
		for(i = 0; i < 26; i++)
			letters[i] = 0;
		for(i = 0; i < n; i++)
			letters[str[i] - 'a']++;
		quicksort(letters, 0, 25);
		i = 0;
		while(letters[i] == 0)
			i++;
		if(i == 26){
			printf("YES");
			return 0;
		}
		t = &letters[i];
		if((c = countdistinct(t, 26 - i)) >= 3)
			printf("NO");
		else if(c == 2){
			i++;
			while(letters[i] == letters[i - 1])
				i++;
			f = &letters[i - 1] - t + 1;
			s = 26 - i;
			if(f > 1 && s > 1)
				printf("NO");
			else if(f == 1)
				if(letters[i - 1] == 1)
					printf("YES");
				else
					printf("NO");
			else if(s == 1)
				if(letters[i] - letters[i - 1] == 1)
					printf("YES");
				else
					printf("NO");
		}
		else
			printf("YES");
		return 0;
}