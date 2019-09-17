#include<iostream>
#include<queue>

using namespace std; 

long long dp[101][21];
int main(){
	int n;
	int num;
	queue<int> q;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		scanf("%d",&num);
		q.push(num);
	}
	scanf("%d",&num);
	
	dp[1][q.front()] = 1;
	q.pop();
	
	int cnt=1;
	while(!q.empty()){
		int r = q.front();
		q.pop();
		for(int i=0;i<=20;i++){
			if(dp[cnt][i] > 0){
				if(i+r <= 20)
					dp[cnt+1][i+r] += dp[cnt][i];
				
				if(i-r >=0)
					dp[cnt+1][i-r] += dp[cnt][i];
				
			}
		}
		cnt++;
	}
	
	
	printf("%lld\n",dp[n-1][num]);
	
	
}
