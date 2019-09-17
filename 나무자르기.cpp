#include<stdio.h>
#include<iostream>

using namespace std;

int arr[1000001];

int max_func(int a, int b){
	return a > b ? a : b;
}

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	
	int high, mid;
	int low=0;
	
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
		high = max_func(arr[i], high);
	}
	
	long long sum=0;
	int max=0;
	
	while(low <= high){
		mid = (low + high) / 2;
		
		
		
		sum=0;
		for(int i=0;i<n;i++){
			if(arr[i] > mid)
				sum += arr[i] - mid;
		}
		
		
		
		if(sum >= m){
			max = max_func(max, mid);
			low = mid+1;
			
			
			
			
		}
		else{
			high = mid-1;	
		}
		
		
	}
	printf("%d\n", max);
	
	
} 
