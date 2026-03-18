#include <bits/stdc++.h>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> ans;

    for(int i=0; i<n-i && i<m-i; ++i) {
        for(int j=i; j<m-i; ++j) ans.push_back(mat[i][j]);
        for(int j=i+1; j<n-i; ++j) ans.push_back(mat[j][m-i-1]);
        for(int j=m-i-2; j>=i && i+1<n-i; --j) ans.push_back(mat[n-i-1][j]);
        for(int j=n-i-2; j>i && i+1<m-i; --j) ans.push_back(mat[j][i]);
    }
    return ans;
}

int main(void) {
    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>v[i][j];
    for(int i: spirallyTraverse(v)) cout<<i<<" ";
}