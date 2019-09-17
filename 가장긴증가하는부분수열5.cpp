#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<vector<int>> dp;
vector<int> arr;
stack<int> s;

int max(int a, int b){
	return a>b?a:b;
}

void find(int idx){
	if(dp[idx][1] == idx){
		s.push(arr[idx]);
		return;
	}
	s.push(arr[idx]);
	find(dp[idx][1]);
} 
int main(){
	int n;
	scanf("%d",&n);
	
	arr.assign(n,0);
	dp.assign(n,vector<int>(2));
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		dp[i][1] = i;
	}
	
	int result = 0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(arr[j] > arr[i]){
				
				if(dp[i][0]+1 > dp[j][0])
					dp[j][1] = i;
				dp[j][0] = max(dp[j][0],dp[i][0] + 1);
				
			}
		}
		if(dp[result][0] < dp[i][0]){
			result = i;
		}
	}
	find(result);
	printf("%d\n",dp[result][0]+1);
	while(!s.empty()){
		printf("%d ",s.top());
		s.pop();
	}
	
}
