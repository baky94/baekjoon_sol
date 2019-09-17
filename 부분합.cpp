#include<stdio.h>



int minf(int a, int b){
	return a<b?a:b;
}

int main(){
	int arr[100001];
	int n,m;
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	int sum = arr[0];
	int min = 99999;
	int low = 0;
	int high = 0;
	
	while(low<=high && high < n){
		if(sum < m){
			high++;
			sum += arr[high];
		}
		else if(sum == m){
			min = minf(min, high-low+1);
			high++;
			sum += arr[high];
		}
		else{
			min = minf(min, high-low+1);
			
			sum -= arr[low];
			low++;
		}
	}
	if(min == 99999){
		min = 0;
	}
	printf("%d\n",min);
}
