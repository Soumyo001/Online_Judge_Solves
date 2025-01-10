#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool isValid(int x,int y,int n,int m,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        return x>=0 && y>=0 && x<n && y<m && grid[x][y]==1 && !vis[x][y];
    }
    void dfs(int& k,int x,int y,int n,int m,vector<vector<int>>& grid,vector<vector<bool>>& vis){
        int dx[] = {0,0,1,-1,1,1,-1,-1};
        int dy[] = {1,-1,0,0,-1,1,-1,1};
        ++k;
        vis[x][y]=true;
        for(int i=0;i<8;++i){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isValid(nx,ny,n,m,grid,vis)) dfs(k,nx,ny,n,m,grid,vis);
        }
    }

    int findMaxArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(!vis[i][j] && grid[i][j]==1){
                    int k=0;
                    dfs(k,i,j,n,m,grid,vis);
                    c = max(c,k);
                }
            }
        }
        return c;
    }
};

int main(){
	int tc=1;
	// cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
    }
	return 0;
}