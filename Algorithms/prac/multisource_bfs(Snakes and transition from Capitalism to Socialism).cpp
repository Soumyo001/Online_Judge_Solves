#include<bits/stdc++.h>
using namespace std;

bool is_valid(int x, int y, int n, int m, vector<vector<bool>>& vis){
    return x>=0 && y>=0 && x<n && y<m && !vis[x][y];
}

int mbfs(vector<pair<int,int>>& s,int n,int m,vector<vector<bool>>& vis,vector<vector<int>>& level,vector<vector<int>>& graph){
    queue<pair<int,int>> q;
    int dx[] = {0,  0, 1, -1,  1, 1, -1, -1};
    int dy[] = {1, -1, 0,  0, -1, 1,  1, -1};
    int ans = INT_MIN;
    for(const auto& i:s){
        q.push(i);
        vis[i.first][i.second] = true;
        level[i.first][i.second] = 0;
        ans = max(ans, level[i.first][i.second]);
    }
    while(!q.empty()){
        auto v = q.front();q.pop();
        int x = v.first;
        int y = v.second;
        for(int i=0;i<8;++i){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(is_valid(nx,ny,n,m,vis)){
                q.push({nx,ny});
                vis[nx][ny] = true;
                level[nx][ny] = level[x][y] + 1;
                ans = max(ans, level[nx][ny]);
            }
        }
    }
    return ans;
}

void solve(){
    int n,m;cin>>n>>m;
    vector<vector<int>> graph(n, vector<int>(m, 0));
    vector<vector<int>> level(n, vector<int>(m, INT_MAX));
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<pair<int,int>> s;
    int mx = INT_MIN;
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) {
        cin>>graph[i][j];
        mx = max(mx, graph[i][j]);
    }
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) if(graph[i][j] == mx) s.push_back({i,j});
    cout<<mbfs(s,n,m,vis,level,graph)<<"\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}