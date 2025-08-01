#include<bits/stdc++.h>
using namespace std;


bool is_valid(int x, int y, int n, int m, const vector<vector<bool>>& vis, const vector<vector<char>>& grid){
    return x>=0 && y>=0 && x<n && y<m && !vis[x][y] && grid[x][y] == '1';
}

void dfs(int x, int y, int n, int m, vector<vector<bool>>& vis, vector<vector<char>>& grid, vector<int>& dx, vector<int>& dy){
    vis[x][y] = true;
    for(int i=0;i<4;++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_valid(nx, ny, n, m, vis, grid)) dfs(nx,ny,n,m,vis,grid,dx,dy);
    }
}

int numIslands(vector<vector<char>>& grid) {
    vector<int> dx = {0,  0, 1, -1};
    vector<int> dy = {-1, 1, 0,  0};
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int ct = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(!vis[i][j] && grid[i][j] == '1'){
                ++ct;
                dfs(i,j,n,m,vis,grid,dx,dy);
            }
        }
    }
    return ct;
}

int main(void){
    vector<vector<char>> grid;
    int n,m;cin>>n>>m;
    for(int i=0;i<n;++i){
        vector<char> g;
        for(int j=0;j<m;++j){
            char c;cin>>c;
            g.push_back(c);
        }
        grid.push_back(g);
    }

    cout<<numIslands(grid)<<"\n";
}