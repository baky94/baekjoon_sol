#include<stdio.h>

int main(){
	char s[101];
	int result[26];
	
	for(int i=0;i<26;i++){
		result[i] = -1;
	}
	
	scanf("%s",&s);
	getchar();
	
	
	
	for(char j='a';j <= 'z';j++){
		int i=0;
		while(s[i] != NULL){
			if(j == s[i] && result[j-'a'] == -1){
				result[j-'a'] = i;
			}
			i++;
		}
	}
	for(int i=0;i<26;i++){
		printf("%d ",result[i]);
	}
	
	
}
