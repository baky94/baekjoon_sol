#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int abs(int num){
    return num>0 ? num : num*(-1);
}
int max(int a, int b){
    return a>b ? a: b;
}

int cal(vector<int> &idx){
    int sum = 0;
    for(int i=1;i<idx.size();i++){
        sum += abs(idx[i]-idx[i-1]);
    }
    return sum;
}

int main(){
    int n;
    cin >> n;

    vector<int> idx(n);
    for(int i=0;i<n;i++){
        cin >> idx[i];
    }

    sort(idx.begin(), idx.end());

    int maximum = 0;

    do{
        int tmp = cal(idx);
        maximum = max(tmp, maximum);

    }while(next_permutation(idx.begin(), idx.end()));

    cout << maximum << endl;
    return 0;

}
