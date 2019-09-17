#include<stdio.h>

int arr[10001];

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	for(int i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	
	int cnt=0;
	int sum=0;
	int tmp;
	
	for(int i=0;i<n;i++){
		tmp = i;
		sum = 0;
		while(sum <= m && tmp <= n){
			if(sum == m){
				cnt++;
				break;
			}
			sum += arr[tmp];
			tmp++;
		}
	}
	
	
	printf("%d\n",cnt);
	
	return 0;
}
