#include <bits/stdc++.h>

using namespace std;

class Solution {
  public:
    bool isValid(int x, int y, int n, int m, vector<vector<bool>>& vis){
        return x>=0 && y>=0 && x<m && y<n && !vis[y][x];
    }
    void dfs(int x, int y, int n, int m, vector<vector<bool>>& vis, vector<vector<int>>& mat){
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        vis[y][x] = true;
        for(int i=0;i<4;++i){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(isValid(nx,ny,n,m,vis) && mat[y][x]<=mat[ny][nx]) 
                dfs(nx,ny,n,m,vis,mat);
        }
    }
    int countCoordinates(vector<vector<int> > &mat) {
        int c = 0;
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis1(n,vector<bool>(m,false));
        vector<vector<bool>> vis2(n,vector<bool>(m,false));

        for(int i=0;i<n;++i) dfs(0,i,n,m,vis1,mat);
	    for(int i=0;i<m;++i) dfs(i,0,n,m,vis1,mat);
        for(int i=0;i<n;++i) dfs(m-1,i,n,m,vis2,mat);
	    for(int i=0;i<m;++i) dfs(i,n-1,n,m,vis2,mat);

        for(int i=0;i<n;++i)
            for(int j=0;j<m;++j) if(vis1[i][j] && vis2[i][j]) ++c;

        return c;
    }
};

int main() {
    int t=1;
    //cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > arr(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.countCoordinates(arr);
        cout << ans << "\n";
    }
    return 0;
}
