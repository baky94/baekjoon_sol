#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

long long arr[202][202];

long long min(long long a, long long b){
	return a<b?a:b;
}


void f(int a, int z, long long k,int len){
	int tmp = a+z;
	if(len ==0){
		return;
	}
	if(a == 0){
		printf("z");
		f(a,z-1,k,len-1);
	}
	else if(z == 0){
		printf("a");
		f(a-1,z,k,len-1);
	}
	else{
		
		if(arr[tmp][z+1] >= k){
			printf("a");
			f(a-1,z,k,len-1);
		}
		else{
			printf("z");
			f(a,z-1,k-arr[tmp][z+1],len-1);
		}
		
	}
	
	
}

int main(){
	int n,m;
	long long k;
	string s="";
	scanf("%d %d %lld",&n,&m,&k);
	int nm = n+m+1;
	
	arr[2][1] = arr[2][2] = 1;
	for(int i=3;i<=nm;i++){
		arr[i][1] = arr[i][i] = 1;
		for(int j=2;j<i;j++){
			arr[i][j] = min(arr[i-1][j-1] + arr[i-1][j], 1000000001);
		}
	}
	
	if(k > arr[n+m+1][m+1]){
		printf("-1");
		return 0;
	}
	f(n,m,k,n+m);
	
	
	
}
