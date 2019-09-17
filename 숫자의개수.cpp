#include<stdio.h>

int main(){
	int a[3];
	int cnt[10]={0,};
	
	long long result = 1;
	
	for(int i=0;i<3;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<3;i++){
		result *= a[i];
	}
	
	//printf("%lld\n",result);
	
	if(result == 0){
		printf("0\n");
		return 0;
	}
	else{
		while(result != 0){
			cnt[result%10]++;
			result /= 10;
		}
		for(int i=0;i<10;i++){
			printf("%d\n",cnt[i]);
		}
	}
}
