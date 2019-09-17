#include<stdio.h>

int adj[103][103];
int visited[103][103];

int q[21000];
int rear;
int front;
int cnt;
int N,M;

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

void dfs(int r, int c, int e){
	if(r == N && c == M){
		if(cnt > e) cnt = e;
	}
	else{
		adj[r][c] = 0;
		for(int i=0;i<4;i++){
			int nr = r + dr[i];
			int nc = c + dc[i];
			if(adj[nr][nc] == 1){
				dfs(nr,nc,e+1);
			}
		}
		adj[r][c] = 1;
	}
}


int bfs(int r, int c){
	rear = -1;
	front = -1;
	
		//enqueue
		q[++rear] = r;
		q[++rear] = c;
		visited[r][c] = 1;
		while(rear != front){
			r = q[++front];
			c = q[++front];
			if(r == N && c == M){
				return visited[r][c];
			}
			for(int i=0;i<4;i++){
				int nr = r + dr[i];
				int nc = c + dc[i];
				if(adj[nr][nc] == 1 && visited[nr][nc] == 0){
					q[++rear] = nr;
					q[++rear] = nc;
					visited[nr][nc] = visited[r][c] + 1;
				}
				
			}
		}
		return 0;
		
}


int main(){
	scanf("%d %d",&N,&M);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			scanf("%1d",&adj[i][j]);
		}
	}
	printf("%d\n",bfs(1,1));
	
	return 0; 
}
