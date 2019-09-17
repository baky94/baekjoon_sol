#include<iostream>
#include<stack>
#include<vector>

using namespace std;



vector<vector<int>> arr;
stack<int> s;
int visit[32002];


void find(int x){
	visit[x] = true;
	for(int a : arr[x])
		if(!visit[a])
			find(a);
	s.push(x);
	
}

int main(){
	int n,m;
	int maxnum=0;
	scanf("%d %d",&n,&m);
	arr.resize(n+1);
	
	
	int a, b;
	for(int i=0;i<m;i++){
		scanf("%d %d",&a,&b);
		arr[a].push_back(b);
	}
	for(int i=1;i<=n;i++){
		if(!visit[i])
			find(i);
		
	}
	
	
	while(s.size()){
		printf("%d",s.top());
		s.pop();
		if(!s.empty())
			printf(" ");
	}
	
	
}
