#include <bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>>& v){
    int n = v.size();
    int m = v[0].size();
    vector<int> x;
    for(int i=0;i<n-i && i<m-i;++i){
        for(int j=i;j<m-i;++j) cout<<v[i][j]<<" ";
        for(int j=i+1;j<n-i;++j) cout<<v[j][m-1-i]<<" ";
        for(int j=m-i-2;j>=i && i+1<n-i;--j) cout<<v[n-i-1][j]<<" ";
        for(int j=n-i-2;j>i && i+1<m-i;--j) cout<<v[j][i]<<" ";
    }
    return x;
}

int main(void){
	int n,m;cin>>n>>m;
    vector<vector<int>> v(n, vector<int>(m));
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) cin>>v[i][j];
    vector<int> a = spiralMatrix(v);

}