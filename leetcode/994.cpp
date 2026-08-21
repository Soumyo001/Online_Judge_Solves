#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_valid(int x, int y, int n, int m, vector<vector<int>>& dist, vector<vector<int>>& grid) {
        return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1 && !dist[x][y];
    }

    int mbfs(vector<vector<int>>& grid, vector<vector<int>>& dist, vector<pair<int, int>>& s, int n, int m, int fresh, vector<int>& dx, vector<int>& dy) {
        queue<pair<int, int>> q;
        for(const pair<int, int>& i : s) q.push(i), dist[i.first][i.second] = 0;
        int mx = 0;
        int found = 0;
        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(is_valid(nx, ny, n, m, dist, grid)) {
                    ++found;
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y] + 1;
                    grid[nx][ny] = 2;
                    mx = max(mx, dist[nx][ny]);
                }
            }
        }
        return found == fresh ? mx : -1;
    }


    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0));
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {-1, 1, 0, 0};
        vector<pair<int, int>> s;
        int fresh = 0;
        for(int i = 0; i < n; ++i) 
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 2) s.push_back({i, j});
                else if(grid[i][j] == 1) ++fresh;
            }
        
        return mbfs(grid, dist, s, n, m, fresh, dx, dy);
    }
};

int main(void) {
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i =0 ; i < n ; ++i) for(int j =0; j < m; ++j) cin >> grid[i][j];
    Solution sol;

    cout<<sol.orangesRotting(grid);
}