#include<stdio.h>


#define INF 0
int arr[501][501];

void floyd(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(arr[j][i] != INF && arr[i][k] != INF){
					arr[j][k] = 1;
				}
			}
		}
	}
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int a,b;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i][j] = INF;
		}
		arr[i][i] = 0;
	}
	
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		arr[b][a] = 1;
	}
	floyd(n);
	int sum=0;
	int cnt=0;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<=n;j++){
			if(arr[i][j] == INF  && arr[j][i] != INF)
				arr[i][j] = arr[j][i];
			sum+= arr[i][j];
			//printf("%d ",arr[i][j]);
		}
		//printf("\n");
		if(sum == n-1){
			cnt++;
		}
	}
	printf("%d\n",cnt);
}
