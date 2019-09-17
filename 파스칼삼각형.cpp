#include<iostream>
#include<vector>

using namespace std;

int arr[31][31];

int main(){
	int r,c,w;
	scanf("%d %d %d",&r,&c,&w);
	
	arr[1][1] = arr[2][1] = arr[2][2] = 1;
	for(int i=3;i<r+w;i++){
		arr[i][1] = 1;
		arr[i][i] = 1;
		for(int j=2;j<i;j++){
			arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
		}
	}
	int tmp = c;
	int sum=0;
	for(int i=r;i<r+w;i++){
		for(int j=c;j<=tmp;j++){
			sum += arr[i][j];
		}
		tmp++;
	}
	printf("%d\n",sum);
	
}
