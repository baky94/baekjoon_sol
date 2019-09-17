#include<stdio.h>
#include<string.h>
int count;

void recursive(int tmp){

    if(tmp>2){
        recursive(tmp-3);
        recursive(tmp-2);
        recursive(tmp-1);
    }
    else if(tmp>1){
        recursive(tmp-2);
        recursive(tmp-1);
    }
    else if(tmp>0){
        recursive(tmp-1);
    }
    else{
        count++;
    }
}

int main(){
    int cas;
    int temp;
    int result[100];
    int i;
    scanf("%d", &cas);
    for(i=0;i<cas;i++){
        scanf("%d", &temp);
        count=0;
        recursive(temp);
        result[i] = count;
    }

    for(i=0;i<cas;i++){
        printf("%d\n", result[i]);
    }
}
