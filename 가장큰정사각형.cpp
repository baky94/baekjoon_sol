#include<stdio.h>

int arr[1002][1002];

int min(int a, int b, int c){
	int tmp;
	if(a < b){
		tmp = a;
	}
	else
		tmp = b;
	return tmp < c?tmp:c;
}
int max(int a, int b){
	return a>b?a:b;
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%1d",&arr[i][j]);
		}
	}
	int result=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j] > 0){
				arr[i][j] = min(arr[i-1][j-1],arr[i-1][j], arr[i][j-1])+1;
				result = max(result,arr[i][j]);
			}
		}
	}
	printf("%d\n",result*result);
	
}
