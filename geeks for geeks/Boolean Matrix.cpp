#include <bits/stdc++.h>
using namespace std;

void booleanMatrix(vector<vector<int>>& v){
    int n = v.size();
    int m = v[0].size();
    vector<bool> row_vis(n, false);
    vector<bool> col_vis(m, false);
    set<pair<int,int>> s;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(v[i][j]==1) s.insert({i,j});
        }
    }
    for(auto& pos:s){
        if(!row_vis[pos.first]){
            for (int j = 0; j < m; ++j)
                v[pos.first][j] = 1;
            row_vis[pos.first] = true;
        }
        if(!col_vis[pos.second]){
            for(int i = 0; i < n; ++i)
                v[i][pos.second] = 1;
            col_vis[pos.second] = true;
        }
    }
}

int main(void){
	int n,m;cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) cin>>v[i][j];
    booleanMatrix(v);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j) cout<<v[i][j]<<" ";
        cout<<"\n";
    }
}