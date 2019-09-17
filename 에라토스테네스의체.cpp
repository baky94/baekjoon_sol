#include<stdio.h>

int prime[10000];

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	
	prime[0] = prime[1] = 1;
	for(int i=2;i<=n/2+1;i++){
		if (2*i <= n){
			prime[2*i] = 1;
		}
		if (3*i <= n){
			prime[2*i] = 1;
		}
		if (5*i <= n){
			prime[2*i] = 1;
		}
		if (7*i <= n){
			prime[2*i] = 1;
		}
		if(i > 7 && prime[i] == 0){
			int j = i;
			while(j*i <= n){
				prime[j*i] = 1;
				j++;
			}
		}
	}
	int cnt=0;
	int check=0;
	for(int i=2;i<=n;i++){
		if(prime[i] == 0){
			int j=1;
			while(i*j <= n){
				if(prime[i*j] != 2){
					cnt++;
					prime[i*j] = 2;
					if(cnt == k){
						printf("%d\n",i*j);
						check=1;
						break;
					}
				}
				
				j++;
			}
		}
		if(check == 1)	break;
		
	}
}
