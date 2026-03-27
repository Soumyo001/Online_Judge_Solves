#include <bits/stdc++.h>
using namespace std;

class BIT {
private:
    int n,m;
    vector<vector<int>> bit;
public:
    BIT(int n,int m): n(n),m(m),bit(n+1,vector<int>(m+1,0)) { }
    void update(int y,int x,int val) {
        for(int i=y;i<=n;i=i+(i & -i)) {
            for(int j=x;j<=m;j=j+(j & -j)) {
                bit[i][j] += val;
            }
        }
    }
    int sum(int y,int x) {
        int sum = 0;
        for(int i=y;i>0;i=i-(i & -i)) {
            for(int j=x;j>0;j=j-(j & -j)) {
                sum += bit[i][j];
            }
        }
        return sum;
    }
};

int main(void) {
    int n,q;cin>>n>>q;
    vector<vector<char>> v(n+1,vector<char>(n+1));
    BIT bit(n,n);
    for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) cin>>v[i][j],bit.update(i,j,(v[i][j]=='*'?1:0));
    while(q--){
        int op;cin>>op;
        if(op == 1) {
            int y,x;cin>>y>>x;
            v[y][x]=(v[y][x] == '*'?'.':'*');
            bit.update(y,x,(v[y][x]=='*'?1:-1));
        } else {
            int y1,x1,y2,x2;cin>>y1>>x1>>y2>>x2;
            cout<<bit.sum(y2,x2)-bit.sum(y1-1,x2)-bit.sum(y2,x1-1)+bit.sum(y1-1,x1-1)<<"\n";
        }
    }
}