#include <bits/stdc++.h>
using namespace std;

bool is_valid(int x, int y, int n, int m) {
    return x >=  0 && y >= 0 && x < n && y < m;
}
vector<vector<int>> searchWord(vector<vector<char>> grid, string word) {
    // Code here
    vector<int> dx = {0,  0, 1, -1,  1, 1, -1, -1};
    vector<int> dy = {-1, 1, 0,  0, -1, 1, -1,  1};
    vector<pair<int, int>> index;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> ans;
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j) if(grid[i][j] == word[0]) index.push_back({i, j});
    
    bool found = true;
    for(const pair<int,int>& idx: index) {
        for(int i=0; i<8; ++i) {
            found = true;
            int nx = idx.first + dx[i];
            int ny = idx.second + dy[i];
            for(int j=1; j<word.length(); ++j) {
                if(is_valid(nx, ny, n, m) && grid[nx][ny] == word[j]) {
                    // ans.push_back({nx, ny});
                    nx += dx[i];
                    ny += dy[i];
                    
                } else {
                    found = false;
                    break;
                }
            }
            if(found) ans.push_back({idx.first, idx.second});
        }
    }
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}

int main(void){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0;i<n;++i)for(int j=0;j<m;++j) cin>>v[i][j];
    string s;cin>>s;
    vector<vector<int>> ans = searchWord(v, s);
    for(auto& i:ans) cout<<i[0]<<" "<<i[1]<<"\n";
}