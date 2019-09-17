#include<stdio.h>

int arr[1001][3];
int dp[1001][3];

int min(int a, int b){
	return a > b ? b : a;
}

int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	
	
	for(int i=1;i<N;i++){
		dp[i][0] = arr[i][0] + min(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = arr[i][1] + min(dp[i-1][0],dp[i-1][2]);
		dp[i][2] = arr[i][2] + min(dp[i-1][0],dp[i-1][1]);
	}
	
	int result = min(dp[N-1][0],dp[N-1][1]);
	result = min(result, dp[N-1][2]);
	
	printf("%d\n",result);
	
}
