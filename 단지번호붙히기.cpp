#include<algorithm>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

int arr[26][26];
int v[26][26];
int q[2000];

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

int dfs(int a, int b){
	int result=1;
	stack<pair<int,int>> s;
	s.push(make_pair(a,b));
	v[a][b] = 1;
	
	while(!s.empty()){
		pair<int,int> p = s.top();
		s.pop();
		int r = p.first;
		int c = p.second;
		
		for(int i=0;i<4;i++){
			int nr = r + dr[i];
			int nc = c + dc[i];
			
			if(arr[nr][nc] == 1 && v[nr][nc] == 0){
				s.push(make_pair(nr,nc));
				v[nr][nc] = v[r][c] + 1;
				result++;
			}
		}
	}
	
	return result;
	
}

int bfs(int a, int b){
	int result=1;
	int rear = -1;
	int front = -1;
	
	q[++rear] = a;
	q[++rear] = b;
	
	v[a][b] = 1;
	
	while(rear != front){
		int r = q[++front];
		int c = q[++front];
		
		for(int k=0;k<4;k++){
			int nr = r+ dr[k];
			int nc = c + dc[k];
			
			if(arr[nr][nc] == 1 && v[nr][nc] == 0){
				q[++rear] = nr;
				q[++rear] = nc;
				v[nr][nc] = v[r][c] + 1;
				result++;
			}
		}
	}
	return result;
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d",&arr[i][j]);
			v[i][j] = 0;
		}
	}
	
	int cnt=0;
	vector<int> vc;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j] == 1 && v[i][j] == 0){
				cnt++;
				//vc.push_back(dfs(i,j));
				vc.push_back(bfs(i,j));
			}
		}
	}
	sort(vc.begin(),vc.end());
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%d\n",vc[i]);
	}
	
	
	
}
