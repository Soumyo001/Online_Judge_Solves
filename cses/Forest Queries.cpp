#include <bits/stdc++.h>
using namespace std;

class BIT {
private:
    int n, m;
    vector<vector<int>> bit;
public:
    BIT(int n, int m): n(n),m(m),bit(n+1,vector<int>(m+1)) { }
    void update(int x, int y, int val) {
        for(int i=x; i<=n; i=i+(i&-i)) 
            for(int j=y; j<=m; j=j+(j&-j))
                bit[i][j]+=val;
    }
    int sum(int x, int y) {
        int res = 0;
        for(int i=x; i>0; i=i-(i&-i)) 
            for(int j=y; j>0; j=j-(j&-j))
                res+=bit[i][j];
        return res;
    }
};

int main(void) {
    int n,q; cin >> n >> q;
    vector<vector<char>> grid(n+1, vector<char>(n+1));
    BIT bit(n,n);
    for(int i=1; i<=n; ++i)
        for(int j=1; j<=n; ++j) cin >> grid[i][j], bit.update(i,j,grid[i][j]=='*'?1:0);
    while(q--) {
        int x1,y1,x2,y2; cin >> y1 >> x1 >> y2 >> x2;
        cout << bit.sum(y2, x2)
                - bit.sum(y2, x1 - 1)
                - bit.sum(y1 - 1, x2)
                + bit.sum(y1 - 1, x1 - 1)
                << "\n";
    }
}