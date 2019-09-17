#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> arr;
vector<vector<int>> v;


int n,m;

int dr[] = {0,1,0,-1};
int dc[] = {1,0,-1,0};

int bfs(){
    int maxnum=0;
    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == 0 && arr[i][j] == 1){
                q.push(make_pair(i,j));
                v[i][j] = 1;
                
            }
        }
    }
    
    while(!q.empty()){
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nr = r + dr[k];
            int nc = c + dc[k];
            if(nr >=0 && nr <n && nc >= 0 && nc < m)
            if(v[nr][nc] == 0 && arr[nr][nc] == 0){
                q.push(make_pair(nr,nc));
                v[nr][nc] = v[r][c] + 1;
                if(v[nr][nc] > maxnum){
                    maxnum = v[nr][nc];
                }
            }
        }

    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == 0 && arr[i][j] == 0){
                return -1;
            }
        }
    }
    return maxnum;
}

int main(){
    scanf("%d %d",&m,&n);
    arr.assign(n,vector<int>(m));
    v.assign(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int maxnum = bfs();
    if(maxnum == 0){
        printf("0\n");
    }
    else if(maxnum == -1){
        printf("-1\n");
    }
    else{
        printf("%d\n",maxnum-1);
    }

    

}
