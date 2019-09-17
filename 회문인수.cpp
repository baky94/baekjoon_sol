#include<stdio.h>
int q[10000];


int find(int num){
	int result;
	int rear,tmp;
	
	for(int i=2;i<=64;i++){
		tmp = num;
		rear = -1;
		//printf("%d\n",i);
		while(tmp != 0){
			q[++rear] = tmp%i;
			tmp = tmp/i;
			//printf("%d ",q[rear]);
		}
		//printf("\n");
		result = 1;
		for(int j=0;j<(rear+1)/2;j++){
			if(q[j] != q[rear-j]){
				result = 0;
			}
		}
	if(result == 1){
		//printf("%d\n",i);
		return 1;
	}
	
	}
	return 0;
	
}

int main(){
	
	int T;
	int number;
	int result;
	scanf("%d",&T);
	
	for(int tc=1;tc<=T;tc++){
		scanf("%d",&number);
	
		result = find(number);
		printf("%d\n",result);
	}
	return 0;
	
}
