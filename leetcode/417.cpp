#include<bits/stdc++.h>
using namespace std;

bool is_valid(int x,int y,int nx,int ny,int n,int m,vector<vector<int>>& heights,vector<vector<bool>>& vis){
    return nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && heights[nx][ny]>=heights[x][y]; 
}

void dfs(int x,int y,int n,int m,vector<vector<int>>& heights,vector<vector<bool>>& vis,vector<int>& dx,vector<int>& dy){
    vis[x][y] = true;
    for(int i=0;i<4;++i){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(is_valid(x,y,nx,ny,n,m,heights,vis)){
            dfs(nx,ny,n,m,heights,vis,dx,dy);
        }
    }
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n = heights.size();
    int m = heights[0].size();
    vector<int> dx = {-1, 1, 0,  0};
    vector<int> dy = { 0, 0, 1, -1};
    vector<vector<bool>> pac(n, vector<bool>(m,false));
    vector<vector<bool>> atl(n, vector<bool>(m,false));
    for(int i=0;i<m;++i){
        dfs(0,i,n,m,heights,pac,dx,dy);
        dfs(n-1,i,n,m,heights,atl,dx,dy);
    }
    for(int i=0;i<n;++i){
        dfs(i,0,n,m,heights,pac,dx,dy);
        dfs(i,m-1,n,m,heights,atl,dx,dy);
    }
    vector<vector<int>> ans;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(pac[i][j] && atl[i][j]) ans.push_back({i,j});
        }
    }
    return ans;
}

int main(void){
    int n,m;cin>>n>>m;
    vector<vector<int>> heights(n, vector<int>(m, 0));
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>heights[i][j];
    vector<vector<int>> ans = pacificAtlantic(heights);
    for(auto i:ans){
        for(auto j:i) cout<<j<<" ";
        cout<<"\n";
    }
}