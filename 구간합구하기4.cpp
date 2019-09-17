#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	
	vector<int> arr(n);
	vector<int> dp(n);
	
	int sum=0;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		sum += arr[i];
		dp[i] = sum;
	}
	int a,b;
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		a--;
		b--; 
		if(a == 0){
			printf("%d\n",dp[b]);
		}
		else{
			printf("%d\n",dp[b] - dp[a-1]);
		}
	}
}
