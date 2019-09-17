#include<stdio.h>

int dp[2][3];
int mdp[2][3];
int arr[100001][3];

int max(int a, int b){
	return a > b ? a:b;
}

int min(int a, int b){
	return a < b ? a:b;
}

int main(){
	
	int n;
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			scanf("%d",&arr[i][j]);
		}
		
		
		
	}
	
	mdp[0][0] = dp[0][0] = arr[0][0];
	mdp[0][1] = dp[0][1] = arr[0][1];
	mdp[0][2] = dp[0][2] = arr[0][2];
	
	
	//max구하기 
	for(int i=1;i<n;i++){
		dp[1][0] = max(dp[0][0], dp[0][1]) + arr[i][0];
		mdp[1][0] = min(mdp[0][0], mdp[0][1]) + arr[i][0];
		
		dp[1][1] = max(max(dp[0][0], dp[0][1]), dp[0][2]) + arr[i][1];
		mdp[1][1] = min(min(mdp[0][0], mdp[0][1]), mdp[0][2]) + arr[i][1];
		
		dp[1][2] = max(dp[0][1], dp[0][2]) + arr[i][2];
		mdp[1][2] = min(mdp[0][1], mdp[0][2]) + arr[i][2];
		
		
		for(int j=0;j<3;j++){
			dp[0][j] = dp[1][j];
			mdp[0][j] = mdp[1][j];
		}
		
		
	}
	
	
	
//	//max구하기 
//	for(int i=1;i<n;i++){
//		dp[i][0] = max(dp[i-1][0], dp[i-1][1]) + arr[i][0];
//		mdp[i][0] = min(mdp[i-1][0], mdp[i-1][1]) + arr[i][0];
//		
//		dp[i][1] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + arr[i][1];
//		mdp[i][1] = min(min(mdp[i-1][0], mdp[i-1][1]), mdp[i-1][2]) + arr[i][1];
//		
//		dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + arr[i][2];
//		mdp[i][2] = min(mdp[i-1][1], mdp[i-1][2]) + arr[i][2];
//	}
	
	int tmp_max = max(max(dp[0][0], dp[0][1]), dp[0][2]);
	int tmp_min = min(min(mdp[0][0], mdp[0][1]), mdp[0][2]);
	
	printf("%d %d\n", tmp_max, tmp_min);
	
}
