#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b){
	return a>b?a:b;
}
int main(){
	int n;
	scanf("%d",&n);
	vector<vector<int>> tri;
	tri.assign(n, vector<int>(n));
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			scanf("%d",&tri[i][j]);
		}
	}
	
	vector<vector<int>> dp;
	dp.assign(n,vector<int>(n));
	dp[0][0] = tri[0][0];
	if(n > 1){
		dp[1][0] = tri[0][0] + tri[1][0];
		dp[1][1] = tri[0][0] + tri[1][1];
	}
	
	
	for(int i=2;i<n;i++){
		dp[i][0] = dp[i-1][0] + tri[i][0];
		dp[i][i] = dp[i-1][i-1] + tri[i][i];
		for(int j= 1;j<i;j++){
			dp[i][j] = max(dp[i-1][j-1],dp[i-1][j])+tri[i][j];
		}
	}
	int result=0;
	for(int i=0;i<n;i++){
		result = max(result, dp[n-1][i]);
	}
	printf("%d\n",result);
	
}
