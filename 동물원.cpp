#include<stdio.h>
int N;
int v2[200004];
int v[100001][3];
int count;

/*
int find(int k){

    if(k%2 == 0){
        if(v[k+1] == 1 || v[k+2] == 1)
            return 1;
    }
    else if(k%2 == 1){
        if(v[k+2] == 1)
            return 1;
    }
    
    return 0;
}

void subset(int depth){
    if( N == depth){
        int check=0;
        for(int i=0;i<N;i++){
            if(v[i] == 1 && find(i) == 1){
                check = 1;
            }
        }
        if(check == 0)  count++;
        return;

    }
    v[depth] = 0;
    subset(depth+1);
    v[depth] = 1;
    subset(depth+1);
}
*/

int subset2(int n){
    v[0][0] = v[0][1] = v[0][2] = 1;
    
    for(int i=1;i<n;i++){
        v[i][0] = (v[i-1][0] + v[i-1][1] + v[i-1][2])%9901;
        v[i][1] = (v[i-1][0] + v[i-1][2])%9901;
        v[i][2] = (v[i-1][0] + v[i-1][1])%9901;
    }
    
    return (v[n-1][0] + v[n-1][1] + v[n-1][2])%9901; 
    
}

int main(){
    int result;
    int n;
    scanf("%d",&n);
    //subset(0);
    result = subset2(n);
    printf("%d\n",result);

    return 0;

}
