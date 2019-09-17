#include<stdio.h>

int adj[1002][1002];

int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	
	adj[1][1] = adj[1][0] = 1;
	
	for(int i=2;i<=a;i++){
		adj[i][i] = adj[i][0] = 1;
		
		for(int j=1;j<i;j++){
			adj[i][j] = (adj[i-1][j-1] + adj[i-1][j])%10007;
		}
	}
	
	printf("%d\n",adj[a][b]%10007);
	
	
	return 0;
}
