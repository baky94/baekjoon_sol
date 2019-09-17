#include<iostream>
#include<vector>

using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	if(n == 2 || n == 5){
		printf("1\n");
		return 0;
	}
	
	vector<int> prime(n+1);
	
	vector<int> q;
	
	prime[0] = prime[1] = 1;
	for(long long i=2;i<=n;i++){
		if(prime[i] == 0){
			q.push_back(i);
			long long j=i;
			while(j*i <= n){
				prime[i*j] = 1;
				j ++;
			}
		}
	}
	int cnt=0;
	int low =0;
	int high = 0;
	int sum = q[0];
	
	while(low<=high){
		if(sum <= n){
			high++;
			if(high >= q.size()){
				break;
			}
			sum += q[high];
		}
		else{
			sum -= q[low++];
		}
		if (sum == n){
			cnt++;
		}
	}
	printf("%d\n",cnt);
}
