#include <bits/stdc++.h>

using namespace std;

int minDiff(vector<int>& v, int m){
    sort(v.begin(), v.end());
    int mini = INT_MAX;
    for(int i=0;i+m-1<v.size();++i)
        mini = min(mini, v[i+m-1]-v[i]);
    return mini;
}

int main(void){
    int n;cin>>n;
    vector<int> v(n,0);
    for(int i=0;i<n;++i) cin>>v[i];
    int m;cin>>m;
    cout<<minDiff(v, m);
}