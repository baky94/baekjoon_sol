#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int comb(int a, int b){
	int t = b;
	int x=1,y=1;
	while(t){
		x *= a--;
		t--;
	}
	while(b){
		y *= b;
		b--;
	}
	return x/y;
}


int main(){
	int m,n,k;
	int sum=0;
	
	scanf("%d",&m);
	vector<int> stone(m);
	for(int i=0;i<m;i++){
		scanf("%d",&stone[i]);
		sum += stone[i];
	}
	scanf("%d",&k);
	
	int tmp=0;
	for(int i=0;i<m;i++){
		if(stone[i] >= k){
			tmp += comb(stone[i],k);
		}
	}
	float result=0;
	result = (float)tmp/comb(sum,k);
	printf("%.10f",result);
	
}
