#include <bits/stdc++.h>
using namespace std;

bool is_valid(int x,int y,int n,int m,vector<vector<char>>& board,string word,int idx,vector<vector<bool>>& vis){
    return x>=0 && y>=0 && x<n && y<m && board[x][y]==word[idx] && !vis[x][y];
}

bool dfs(int x,int y,vector<vector<char>>& board,string word,int n,int m,vector<int>& dx,vector<int>& dy,vector<vector<bool>>& vis,int idx){
    if(idx == word.size() - 1) return true;
    vis[x][y] = true;
    bool res = false;
    for(int i=0;i<4;++i){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(is_valid(nx,ny,n,m,board,word,idx+1,vis)){
            res |= dfs(nx,ny,board,word,n,m,dx,dy,vis,idx+1);
        }
    }
    vis[x][y] = false;
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    vector<int> dx = { 0, 0, -1, 1};
    vector<int> dy = {-1, 1,  0, 0};
    int n = board.size();
    int m = board[0].size();
    vector<pair<int,int>> source;
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) 
            if(board[i][j] == word[0]) source.push_back({i,j});
    bool ans = false;
    for(const auto& i:source){
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        ans|=dfs(i.first,i.second,board,word,n,m,dx,dy,vis,0);
    }
    return ans;
}

int main(void){
    int n,m;cin>>n>>m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0;i<n;++i)for(int j=0;j<m;++j) cin>>v[i][j];
    string word;cin>>word;
    cout<<exist(v,word)<<"\n";
}