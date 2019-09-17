#include<stdio.h>



int main(){
	long long x,y;
	long long result = 4000000001;
	scanf("%lld %lld",&x,&y);
	
	int z = (y*100)/x;
	
//	int cnt=0;
//	int tmp = z;
//	while(z == tmp){
//		y += 1;
//		x += 1;
//		cnt += 1;
//		tmp =  (y*100)/x;
//		
//		
//		
//	}

	if(z >= 99){
		printf("-1");
		return 0;
	}

	int low = 0;
	int high = 2*x;
	int mid;
	
	while(low <= high){
		mid = (low+high)/2;
		
		long long ty = y+mid;
		long long tx = x + mid;
		int tmp = (ty*100)/tx;
		
		if(z == tmp){
			low = mid + 1;
		}
		else{
			if(mid < result){
				result = mid;
			}
			high = mid - 1;
		}
	}
	
	printf("%lld\n",result);
	
	
}
