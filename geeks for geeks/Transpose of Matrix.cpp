#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> ans(m, vector<int>(n,0));
    
    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) ans[j][i] = mat[i][j];
    }
    return ans;
}

int main(void) {
    int n, m; cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>v[i][j];
    vector<vector<int>> ans = transpose(v);
    for(const auto& i: ans) {
        for(int j: i) cout<<j<<" ";
        cout<<"\n";
    }
}