#include <bits/stdc++.h>
using namespace std;
vector<int> dx =   { 0,  0, -1,  1};
vector<int> dy =   {-1,  1,  0,  0};
vector<char> dir = {'L','R','U','D'};
vector<pair<int,int>> mSource;
pair<int,int> s;
int n,m;

void inputGraph(vector<vector<char>>& g){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>g[i][j];
            if(g[i][j] == 'M') mSource.push_back({i,j});
            if(g[i][j] == 'A') {
                s.first = i;
                s.second = j;
            }
        }
    }
}

bool is_boundary(int x, int y){
    return x == 0 || x == n-1 || y == 0 || y == m-1;
}

bool is_valid(int x, int y, vector<vector<int>>& dist, vector<vector<char>>& g){
    return x>=0 && y>=0 && x<n && y<m && g[x][y] != '#' && dist[x][y] == INT_MAX;
}

void mbfs(vector<vector<int>>& mDist, vector<vector<char>>& g){
    queue<pair<int,int>> q;
    for(const auto& i:mSource){
        q.push({i.first, i.second});
        mDist[i.first][i.second] = 0;
    }
    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();
        for(int i=0;i<4;++i){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(is_valid(nx,ny,mDist,g)){
                mDist[nx][ny] = mDist[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
}

void bfs(vector<vector<int>>& aDist, vector<vector<int>>& mDist, vector<vector<int>>& parent, vector<vector<char>>& g, pair<int,int>& b){
    queue<pair<int,int>> q;
    q.push({s.first, s.second});
    aDist[s.first][s.second] = 0;
    parent[s.first][s.second] = -1;
    while (!q.empty())
    {
        auto [x, y] = q.front(); q.pop();
        if(is_boundary(x,y) && aDist[x][y] < mDist[x][y]){
            b.first = x;
            b.second = y;
            return;
        }
        for(int i=0;i<4;++i){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(is_valid(nx,ny,aDist,g) && aDist[x][y] + 1 < mDist[nx][ny]){
                aDist[nx][ny] = aDist[x][y] + 1;
                parent[nx][ny] = i;
                q.push({nx,ny});
            }
        }
    }
    
}

int main(void){
    cin>>n>>m;
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<int>> parent(n, vector<int>(m,-1));
    vector<vector<int>> mDist(n, vector<int>(m, INT_MAX));
    vector<vector<int>> aDist(n, vector<int>(m, INT_MAX));
    pair<int,int> boundary = {-1,-1};
    inputGraph(g);
    mbfs(mDist, g);
    bfs(aDist,mDist,parent,g,boundary);
    if(boundary.first == -1 || boundary.second == -1){
        cout<<"NO\n";
        return 0;
    }
    int x = boundary.first;
    int y = boundary.second;
    vector<char> ans;
    while(parent[x][y] != -1){
        int p = parent[x][y];
        ans.push_back(dir[p]);
        x -= dx[p];
        y -= dy[p];
    }
    reverse(ans.begin(), ans.end());
    cout<<"YES\n"<<ans.size()<<"\n";
    for(char i:ans) cout<<i;

}