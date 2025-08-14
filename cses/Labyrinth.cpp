#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> dx = {0,0,-1,1};
vector<int> dy = {-1,1,0,0};
vector<char> dir = {'L','R','U','D'};

bool is_valid(int x,int y,vector<vector<char>>& g){
    return x>=0 && y>=0 && x<n && y<m && (g[x][y] == '.' || g[x][y] == 'B');
}

pair<int,string> bfs(pair<int,int>& s,vector<vector<char>>& g){
    queue<pair<int,int>> q;
    queue<string> p;
    q.push({s.first,s.second});
    p.push("");
    g[s.first][s.second] = '#';
    vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
    dist[s.first][s.second] = 0;
    while (!q.empty())
    {
        pair<int,int> n = q.front();q.pop();
        string s = p.front();p.pop();
        for(int i=0;i<4;++i){
            int nx = n.first+dx[i];
            int ny = n.second+dy[i];
            if(is_valid(nx,ny,g)){
                dist[nx][ny] = dist[n.first][n.second] + 1;
                if(g[nx][ny] == 'B') return {dist[nx][ny], s+dir[i]};
                q.push({nx,ny});
                p.push(s+dir[i]);
                g[nx][ny] = '#';
            }
        }
    }
    return {-1, ""};
}
//optimal for 1<=n,m<=1000
pair<int,string> bfs2(pair<int,int>& s,vector<vector<char>>& g){
    queue<pair<int,int>> q;
    q.push({s.first,s.second});
    g[s.first][s.second] = '#';
    vector<vector<int>> parent(n, vector<int>(m, -1));
    vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
    dist[s.first][s.second] = 0;
    while (!q.empty())
    {
        pair<int,int> n = q.front();q.pop();
        for(int i=0;i<4;++i){
            int nx = n.first+dx[i];
            int ny = n.second+dy[i];
            if(is_valid(nx,ny,g)){
                parent[nx][ny] = i;
                dist[nx][ny] = dist[n.first][n.second] + 1;
                q.push({nx,ny});
                if(g[nx][ny] == 'B'){
                    string path = "";
                    int cx = nx, cy = ny;
                    while(cx != s.first || cy !=s.second){
                        int p = parent[cx][cy];
                        path+=dir[p];
                        cx-=dx[p];
                        cy-=dy[p];
                    }
                    reverse(path.begin(),path.end());
                    return {dist[nx][ny], path};
                }
                g[nx][ny] = '#';
            }
        }
    }
    return {-1, ""};
}

int main(void){
    cin>>n>>m;
    pair<int,int> s;
    vector<vector<char>> g(n, vector<char>(m));
    for(int i=0;i<n;++i) for(int j=0;j<m;++j){
        cin>>g[i][j];
        if(g[i][j] == 'A') s.first=i,s.second=j;
    }
    pair<int,string> ans = bfs2(s,g);
    if(ans.first == -1) cout<<"NO\n";
    else{
        cout<<"YES\n"<<ans.first<<"\n"<<ans.second;
    }
}