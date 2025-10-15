#include <bits/stdc++.h>
using namespace std;

bool is_valid(int x, int y, int n, int m, vector<vector<char>>& board, vector<vector<bool>>& vis){
    return x>=0 && y>=0 && x<=n-1 && y<=m-1 && !vis[x][y] && board[x][y] == 'O';
}
void dfs(int x,int y,int n,int m,const vector<int>& dx,const vector<int>& dy,
    vector<vector<bool>>& vis,vector<vector<char>>& board){
    vis[x][y] = true;
    for(int i=0;i<4;++i){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(is_valid(nx,ny,n,m,board,vis)) dfs(nx,ny,n,m,dx,dy,vis,board);
    }
}
void solve(vector<vector<char>>& board) {
    const vector<int> dx = {-1, 1, 0,  0};
    const vector<int> dy = { 0, 0, 1, -1};
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for(int i=0;i<n;++i) if(board[i][0] == 'O' && !vis[i][0]) dfs(i,0,n,m,dx,dy,vis,board);
    for(int i=0;i<n;++i) if(board[i][m-1] == 'O' && !vis[i][m-1]) dfs(i,m-1,n,m,dx,dy,vis,board);
    for(int i=0;i<m;++i) if(board[0][i] == 'O' && !vis[0][i]) dfs(0,i,n,m,dx,dy,vis,board);
    for(int i=0;i<m;++i) if(board[n-1][i] == 'O' && !vis[n-1][i]) dfs(n-1,i,n,m,dx,dy,vis,board);
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j) if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
}

int main(void){
    int n,m;cin>>n>>m;
    vector<vector<char>> board(n,vector<char>(m));
    for(int i=0;i<n;++i)for(int j=0;j<m;++j) cin>>board[i][j];
    solve(board);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) cout<<board[i][j]<<" ";
        cout<<"\n";
    }
}