#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};
int n,m;
bool is_valid(int x,int y,vector<vector<char>>& g){
    return x>=0 && y>=0 && x<n && y<m && g[x][y] == '.';
}

void dfs(int x,int y,vector<vector<char>>& g){
    g[x][y] = '#';
    for(int i=0;i<4;++i){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(is_valid(nx,ny,g)) dfs(nx,ny,g);
    }
}

int main(void){
    cin>>n>>m;
    vector<vector<char>> g(n,vector<char>(m));
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>g[i][j];
    int ans = 0;
    for(int i=0;i<n;++i)for(int j=0;j<m;++j) if(g[i][j] == '.') dfs(i,j,g), ++ans;
    cout<<ans;
}
