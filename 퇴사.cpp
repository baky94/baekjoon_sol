#include<stdio.h>

int N=0;
int Ti[16];
int Pi[16];
int cost=0;
int max_value=0;

void dfs(int date, int cost){
    if(date == N+1){
        max_value = max_value > cost ? max_value : cost;
        return;
    }
    if(date + Ti[date] < N+2){
        dfs(date + Ti[date], cost+Pi[date]);
    }

    if(date + 1 < N+2){
        dfs(date + 1, cost);
    }

}

int main(){
    scanf("%d", &N);
    for(int i=0;i<N;i++){
        scanf("%d %d", &Ti[i+1], &Pi[i+1]);
    }

    dfs(1,0);

    printf("%d\n", max_value);

    return 0;
    
}
