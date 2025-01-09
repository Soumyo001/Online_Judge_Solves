#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isValid(int x, int y, int n, int m, vector<vector<bool>>& vis, vector<vector<char>>& grid){
        return x>=0 && y>=0 && x<n && y<m && !vis[x][y] && grid[x][y] == '1';
    }
    void dfs(int x, int y, int n, int m, vector<vector<bool>>& vis, vector<vector<char>>& grid){
        int dx[] = {1,-1,0,0,1,1,-1,-1};
        int dy[] = {0,0,1,-1,1,-1,1,-1};
        vis[x][y] = true;
        for(int i=0;i<8;++i){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isValid(nx,ny,n,m,vis,grid)) dfs(nx,ny,n,m,vis,grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int c = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i,j,n,m,vis,grid);
                    ++c;
                }
            }
        }
        return c;
    }
};

int main() {
    int tc=1;
    // cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}