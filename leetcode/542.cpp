#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_valid(int x,int y,int n,int m,vector<vector<int>>& mat,vector<vector<int>>& dist) {
        return x >= 0 && y >= 0 && x < n && y < m && mat[x][y] == 1 && !dist[x][y];
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {-1, 1, 0, 0};
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<pair<int, int>> s;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(mat[i][j] == 0) s.push_back({i, j});

        queue<pair<int, int>> q;
        for(const pair<int, int>& i : s) q.push(i);
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for(int i =0; i<4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(is_valid(nx,ny,n,m,mat,dist)) {
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
        return dist;
    }
};

int main(void) {
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i =0 ; i < n ; ++i) for(int j =0; j < m; ++j) cin >> grid[i][j];
    Solution sol;

    vector<vector<int>> ans = sol.updateMatrix(grid);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) cout<<ans[i][j]<<" ";
        cout<<"\n";
    }
}