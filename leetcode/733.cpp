#include<bits/stdc++.h>
using namespace std;

bool is_valid(int nx, int ny, int n, int m, int initColor, vector<vector<int>>& image){
    return nx>=0 && ny>=0 && nx<n && ny<m && image[nx][ny] == initColor;
}

void dfs(vector<vector<int>>& image, int sr, int sc, int n, int m, int initColor, int newColor, vector<int>& dx, vector<int>& dy){
    image[sr][sc] = newColor;

    for(int i=0;i<4;++i){
        int nx = sr+dx[i];
        int ny = sc+dy[i];
        if(is_valid(nx,ny,n,m,initColor,image)) dfs(image, nx, ny, n, m, initColor, newColor, dx, dy);
    }
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int initColor = image[sr][sc];
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int n = image.size();
    int m = image[0].size();
    if(initColor != color) dfs(image, sr, sc, n, m, initColor, color, dx, dy);
    return image;
}

int main(void){
    int n,m,sr,sc;
    cin>>n>>m;
    vector<vector<int>> image(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) cin>>image[i][j];
    cin>>sr>>sc;
    image = floodFill(image, sr, sc, 2);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j) cout<<image[i][j]<<" ";
        cout<<"\n";
    }
}