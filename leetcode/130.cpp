#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool is_valid(int x,int y,int n,int m,vector<vector<bool>>& vis,vector<vector<char>>& board) {
        return x >= 0 && y >= 0 && x < n && y < m && board[x][y] == 'O' && !vis[x][y];
    }
    void dfs(int x, int y, int n, int m, vector<vector<char>>& board, vector<vector<bool>>& vis, vector<int>& dx, vector<int>& dy) {
        vis[x][y] = true;
        for(int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(is_valid(nx,ny,n,m,vis,board)) dfs(nx,ny,n,m,board,vis,dx,dy);
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {-1, 1, 0, 0};

        for(int i = 0; i < n; ++i) if(!vis[i][0] && board[i][0] == 'O') dfs(i,0,n,m,board,vis,dx,dy);
        for(int i = 0; i < n; ++i) if(!vis[i][m-1] && board[i][m-1] == 'O') dfs(i,m-1,n,m,board,vis,dx,dy);
        for(int i = 0; i < m; ++i) if(!vis[0][i] && board[0][i] == 'O') dfs(0,i,n,m,board,vis,dx,dy);
        for(int i = 0; i < m; ++i) if(!vis[n-1][i] && board[n-1][i] == 'O') dfs(n-1,i,n,m,board,vis,dx,dy);

        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(!vis[i][j] && board[i][j] == 'O') board[i][j] = 'X';
    }
};

int main(void){
    int n,m;cin>>n>>m;
    vector<vector<char>> board(n,vector<char>(m));
    for(int i=0;i<n;++i)for(int j=0;j<m;++j) cin>>board[i][j];
    Solution sol;
    sol.solve(board);
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j) cout<<board[i][j]<<" ";
        cout<<"\n";
    }
}