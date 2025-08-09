#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> grid(8, vector<int>(8,0));
int dx[] = { 1,  -1,  2, -2, 2, -2, 1, -1};
int dy[] = {-2,  -2, -1, -1, 1,  1, 2,  2};

int getX(char c){
    return c-'a';
}

int getY(char c){
    return c-'1';
}

bool is_valid(int x,int y,vector<vector<bool>>& vis){
    return x>=0 && y>=0 && x<8 && y<8 && !vis[x][y];
}

int bfs(int sx, int sy, int fx, int fy, vector<vector<bool>>& vis, vector<vector<int>>& level){
    queue<pair<int,int>> q;
    q.push({sx,sy});
    vis[sx][sy] = true;
    level[sx][sy] = 0;
    while(!q.empty()){
        auto v = q.front();q.pop();
        int x = v.first;
        int y = v.second;
        for (int i = 0; i < 8; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(is_valid(nx,ny,vis)){
                vis[nx][ny] = true;
                q.push({nx,ny});
                level[nx][ny] = level[x][y] + 1;
            }
        }
        if(level[fx][fy]!=INT_MAX) break;
    }
    return level[fx][fy];
}

int main(void){
    int t;cin>>t;
    while(t--){
        string a,b;cin>>a>>b;
        int sx = getX(a[0]);
        int sy = getY(a[1]);
        int dx = getX(b[0]);
        int dy = getY(b[1]);
        vector<vector<bool>> vis(8, vector<bool>(8, false));
        vector<vector<int>> level(8, vector<int>(8, INT_MAX));
        cout<<bfs(sx,sy,dx,dy,vis,level)<<"\n";
    }
}