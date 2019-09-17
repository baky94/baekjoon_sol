#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int card[11];

int main(){
	int n,k;
	
	vector<int> v;
	vector<int> result;
	scanf("%d",&n);	
	scanf("%d",&k);
	for(int i=0;i<n;i++){
		scanf("%d",&card[i]);
		v.push_back(card[i]);
	}
	vector<int> ind(n);
	vector<int> q;
	for(int i=0;i<k;i++){
		ind[i] = 1;
	}
	sort(v.begin(),v.end());
	string numstring="";
	int numint=0;
	sort(ind.begin(),ind.end());
	
	do{
		for(int i=0;i<n;i++){
			if(ind[i] == 1){
				q.push_back(v[i]);
			}
		}
		do{
			numstring ="";
			for(int i=0;i<k;i++){
				numstring += to_string(q[i]);
			}
			numint = stoi(numstring);
			int check = 0;
			for(int j=0;j<result.size();j++){
				if(result[j] == numint){
					check = 1;
				}
			}
			if(check == 0){
				result.push_back(numint);
			}
		
		}while(next_permutation(q.begin(),q.end()));
		q.clear();
	}while(next_permutation(ind.begin(),ind.end()));
	
//	for(int i=0;i<result.size();i++){
//		printf("%d ",result[i]);
//	}
	printf("%d\n",result.size());
	
	
	
}
