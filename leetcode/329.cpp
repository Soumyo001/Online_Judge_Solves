#include<bits/stdc++.h>
using namespace std;

bool is_valid(int x, int y, int n, int m, vector<vector<int>>& matrix, int curr){
    return x>=0 && y>=0 && x<n && y<m && curr < matrix[x][y];
}

int dfs(int x, int y, int n, int m, vector<vector<int>>& matrix, vector<int>& dx, vector<int>& dy, vector<vector<int>>& dp){
    int ans = 0;
    for(int i=0;i<4;++i){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(is_valid(nx,ny,n,m,matrix,matrix[x][y])){
            if(dp[nx][ny] != -1) ans = max(ans, dp[nx][ny]);
            else ans = max(ans, dfs(nx,ny,n,m,matrix,dx,dy,dp));
        }
    }
    //cout<<ct<<" "<<ans<<" for "<<matrix[x][y]<<" "<<x<<" "<<y<<'\n';
    return dp[x][y]=ans+1;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, -1, 1};
    int n = matrix.size();
    int m = matrix[0].size();
    int ans = INT_MIN;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            //cout<<"starting for: "<<matrix[i][j]<<" "<<i<<" "<<j<<"\n";
            ans = max(ans, dfs(i,j,n,m,matrix,dx,dy,dp));
            //cout<<"final answer: "<<ans<<'\n';
        }
    }
    return ans;
}

int main(void){
    int n,m;cin>>n>>m;
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    for(int i=0;i<n;++i) for(int j=0;j<m;++j) cin>>matrix[i][j];
    cout<<longestIncreasingPath(matrix)<<"\n";
}