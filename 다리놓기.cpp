#include<stdio.h>

int arr[31][31];

int main(){
	//paskal
	arr[1][1] = arr[2][1] = arr[2][2] = 1;
	for(int i=3;i<31;i++){
		arr[i][1] = arr[i][i] = 1;
		for(int j=2;j<i;j++){
			arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
		}
	}
	int t,n,m;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d %d",&n,&m);
		printf("%d\n",arr[m+1][n+1]);
	} 
	return 0; 
}
