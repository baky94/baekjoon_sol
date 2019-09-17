#include<stdio.h>

int adj[1000001];
int a[10];

int main(){
	int number;
	int max=0;
	scanf("%d",&number);
	
	int tmp = number;
	if(tmp == 0){
		printf("1\n");
		return 0;
	} 
	while(tmp != 0){
		a[tmp%10]++;
		if(max < a[tmp%10])	max = a[tmp%10];
		tmp /= 10;
	}
	
	int chk = 0;
	if(max == a[6] || max == a[9]){
		for(int i=0;i<10;i++){
			if(i != 6 && i != 9 && max == a[i])
				chk = 1;
		}
		if(chk == 0){
			max = (a[6]+a[9]+1)/2;
			a[6] = a[9] = 0;
			for(int i=0;i<10;i++){
				if(max < a[i])	max = a[i];
			}
			printf("%d\n",max);
			
		}
		else{
			printf("%d\n",max);
		}
	}
	else printf("%d\n",max);
	
	return 0;
}
