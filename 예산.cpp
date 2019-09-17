#include<stdio.h>

int N,M;
int arr[10001];

int main(){
	int max=0;
	int sum=0;
	scanf("%d", &N);
	for(int i=0;i<N;i++){
		scanf("%d",&arr[i]);
		if(max < arr[i]){
			max = arr[i];
			
		}
		sum += arr[i];
	}
	scanf("%d",&M);
	
	
	if(sum <= M){
		printf("%d\n",max);
		return 0;
	}
	else{
		while(max >= 0){
			sum = 0;
			for(int i=0;i<N;i++){
				if(arr[i] <= max){
					sum += arr[i];
				}
				else
					sum += max;
			}
			
			if(sum <= M){
				printf("%d\n",max);
				return 0; 
			}
			
			else	max--;
			
		}
	}
	
	
}
