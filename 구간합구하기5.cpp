#include<stdio.h>

int arr[1025][1025];
int dp[1025][1025];

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
			dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + arr[i][j];
		}
	}
	int x1,x2,y1,y2;
	int result=0;
	for(int i=0;i<m;i++){
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		result = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1];
		printf("%d\n",result);
	}
}
