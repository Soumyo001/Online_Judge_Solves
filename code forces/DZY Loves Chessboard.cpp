#include <bits/stdc++.h>
using namespace std;
int n,m;

bool is_valid(int x, int y, vector<vector<char>>& v, vector<int>& dx, vector<int>& dy) {
    return x>=0 && y>=0 && x<n && y<m && v[x][y] == '.';
}

void dfs(int x, int y, vector<vector<char>>& v, vector<int>& dx, vector<int>& dy, char c) {
    v[x][y] = c;
    for(int i=0; i<4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(is_valid(nx,ny,v,dx,dy)) dfs(nx,ny,v,dx,dy, (c == 'B' ? 'W':'B'));
    }
}

void solve() {
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for(int i=0; i < n; ++i) {
        for(int j=0; j < m; ++j) {
            cin >> v[i][j];
        }
    }
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            if(v[i][j] == '.') dfs(i,j,v,dx,dy,'B');

    for(int i=0; i<n; ++i) {
        for(int j=0; j<m; ++j) {
            cout << v[i][j];
        }
        cout<<"\n";
    }
}

int main(void) {
    solve();
}