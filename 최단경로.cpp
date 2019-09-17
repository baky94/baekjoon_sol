#include<stdio.h>
#include<queue>
#include<iostream>
#include<vector>
#define INF 987654321

using namespace std;


int main(){
	int v,e;
	int start;
	int a,b,c;
	
	scanf("%d %d",&v,&e);
	
	vector<vector<int>>arr;
	arr.assign(v+1,vector<int>(v+1,0));
	vector<int>visit(v+1);
	
	
	for(int i=1;i<=v;i++){
		for(int j=1;j<=v;j++){
			arr[i][j] = INF;
		}
		visit[i] = INF;
	}
	
	scanf("%d",&start);
	for(int i=0;i<e;i++){
		scanf("%d %d %d",&a,&b,&c);
		arr[a][b] = c;
	}
	queue<int>q;
	q.push(start);
	visit[start] = 0;
	
	while(!q.empty()){
		int r = q.front();
		q.pop();
		for(int i=1;i<=v;i++){
			if(visit[i] > visit[r]+arr[r][i]){
				visit[i] = visit[r] + arr[r][i];
				q.push(i);
			}
		}
		
	}
	
	for(int i=1;i<=v;i++){
		if(visit[i] == INF){
			printf("INF\n");
		}
		else{
			printf("%d\n",visit[i]);	
		}
		
	}
	
	
}
