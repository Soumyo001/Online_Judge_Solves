#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> v(n,vector<int>(m));
    for(int i=0;i<n;++i){
        string s;cin>>s;
        for(int j=0;j<m;++j) v[i][j] = s[j] - '0';
    }
    vector<int> row(n,0), col(m,0);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            row[i]^=v[i][j];
            col[j]^=v[i][j];
        }
    }
    int r=0,c=0;
    for(int i=0;i<n;++i) if(row[i] == 1) ++r;
    for(int j=0;j<m;++j) if(col[j] == 1) ++c;
    cout<<max(r,c)<<"\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}