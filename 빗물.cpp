#include<stdio.h>

int arr[501];
int q[501];

int min(int a,int b){
    return a < b ? a : b;
}

int max(int a,int b){
    return a > b ? a : b;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int j=0;j<m;j++){
        scanf("%d",&arr[j]);
    }
    int left=1,right=1;
    int tmp=0;
    int result=0;
    for(int i=1;i<m-1;i++){
        left = i;
        right = i;
        //øﬁ¬  √÷¥Î ±‰ ∫¿
        for(int j=i-1;j>=tmp;j--){
            if(arr[j] > arr[i]){
                if(arr[j] > arr[left]){
                    left = j;
                }
            }
        }

        //ø¿∏•¬  √÷¥Î ±‰ ∫¿
        
        for(int j=i+1;j<m;j++){
            if(arr[j] > arr[i]){
                if(arr[j] > arr[right]){
                    right = j;
                }
            }
        }


        //≥–¿Ã ±∏«œ±‚
        result += max(min(arr[left],arr[right]) - arr[i], 0);
        //printf("#%d %d\n",i,max(min(arr[left],arr[right]) - arr[i], 0));

        
    }
    printf("%d\n",result);

}
