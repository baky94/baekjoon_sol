#include<stdio.h>
#include<string.h>

char str[1000001];
char alpha[26];
int cnt[26];

int main(){
	int overlap=0;
	scanf("%s",str);
	
	alpha[0] = 'A';
	for(int i=1;i<26;i++){
		alpha[i] = alpha[i-1] + 1;
	}
	int diff = 'a' - 'A';
	
	
	int k=0;
	int max=0;
	int maxidx=0;
	while(str[k] != NULL){
		for(int i=0;i<26;i++){
			if(str[k] == alpha[i] || str[k] == alpha[i]+diff){
				cnt[i]++;
			}
		}
		k++;
	}
	for(int i=0;i<26;i++){
		if(max < cnt[i]){
			max = cnt[i];
			maxidx = i;
		}
	}
	
	for(int i=0;i<26;i++){
		if(max == cnt[i])	overlap++;
	}
	
	if(overlap >= 2)	printf("?\n");
	else{
		printf("%c\n",alpha[maxidx]);
	}
	
	
}
