#include<stdio.h>

int bus[100001][3];
int city[101][101];

#define INF 987654321

int min(int a, int b){
	return a < b ? a: b;
}

void floyd(int n){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(city[j][i] != INF && city[i][k] != INF){
					city[j][k] = min(city[j][k], city[j][i] + city[i][k]);
				}
			}
		}
	}
	
}

int main(){
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int n1,n2,n3;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			city[i][j] = INF;
		}
	}
	
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&n1,&n2,&n3);
		city[n1][n2] = min(n3, city[n1][n2]);
		
	}
	
	floyd(n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i == j || city[i][j] == INF){
				printf("%d ", 0);
			}
			else{
				printf("%d ", city[i][j]);
			}
		}
		printf("\n");
	}
	
	
}
