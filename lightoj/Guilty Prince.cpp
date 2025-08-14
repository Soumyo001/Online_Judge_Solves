#include <bits/stdc++.h>
using namespace std;

bool is_valid(int x, int y, int n, int m, vector<vector<bool>>& vis, vector<vector<char>>& g){
    return x>=0 && y>=0 && x<n && y<m && !vis[x][y] && g[x][y] == '.';
}

void dfs(int x, int y, int n, int m, vector<int>& dx, vector<int>& dy, vector<vector<bool>>& vis, vector<vector<char>>& g, int& ct){
    ++ct;
    vis[x][y] = true;
    for(int i=0;i<4;++i){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(is_valid(nx,ny, n, m, vis, g)) dfs(nx,ny,n,m,dx,dy,vis,g,ct);
    }
}

void solve(int t){
    int n,m;cin>>m>>n;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    pair<int,int> source;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j){
        cin>>g[i][j];
        if(g[i][j] == '@'){
            source.first = i;
            source.second = j;
        }
    }
    vector<int> dx = { 0, 0, 1, -1};
    vector<int> dy = {-1, 1, 0,  0};
    int ct = 0;
    dfs(source.first, source.second, n, m, dx, dy, vis, g, ct);
    cout<<"Case "<<t<<": "<<ct<<"\n";
}

int main(void){
    int t;cin>>t;
    for(int i=1;i<=t;++i) solve(i);
}