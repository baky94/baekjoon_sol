#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int arr[4001][4];

vector<int> ab, cd;

int main(){
	int n;
	scanf("%d",&n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ab.push_back(arr[i][0] + arr[j][1]);
			cd.push_back(arr[i][2] + arr[i][3]);
			
		}
	}
	
	sort(cd.begin(), cd.end());
	
	int cnt=0;
	
	int low = 0;
	int high = n*n;
	int mid,i;
	
	for(i=0;i<ab.size();i++){
		low = 0;
		high = n*n;
		while(low < high){
			mid = (low+high)/2;
			if(ab[i] + cd[mid] < 0){
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}
		
		long long lo_bnd = mid;
		low = 0;
		high = n*n;
		
		while(low < high){
			mid = (low+high)/2;
			if(ab[i] + cd[mid] <= 0){
				low = mid+1;
			}
			else{
				high = mid-1;
			}
		}
		long long up_bnd = mid;
		
		cnt += up_bnd - lo_bnd;
		
	}
	
	printf("%d\n",cnt);
		

	
}
