#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_valid(int x,int y,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dist) {
        return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 0 && !dist[x][y];
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1) return -1;
        if(grid[0][0] == 0 && n == 1) return 1;
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<int> dx = {1,  1, -1 , -1, 0,  0, 1, -1};
        vector<int> dy = {1, -1,  1,  -1, -1, 1, 0,  0,};

        queue<pair<int, int>> q;
        q.push({0,0});
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i < 8; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(is_valid(nx,ny,n,m,grid,dist)) {
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        return !dist[n-1][m-1] ? -1 : dist[n-1][m-1]+1;
    }
};

int main(void) {
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i =0 ; i < n ; ++i) for(int j =0; j < m; ++j) cin >> grid[i][j];
    Solution sol;

    cout<<sol.shortestPathBinaryMatrix(grid);
}