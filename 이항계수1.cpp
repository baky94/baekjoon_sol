#include<stdio.h>

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	
	int a=1;
	int b=1;
	int tmp =k;
	
	while(tmp > 0){
		a *= n;
		n--;
		tmp--;
	}
	while(k > 1){
		b *= k;
		k--;
	}
	printf("%d\n",a/b);
}
