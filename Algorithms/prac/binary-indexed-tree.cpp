#include <bits/stdc++.h>
using namespace std;

class BIT {
private:
    vector<int> bit;
    int n;
public:
    BIT(int n):n(n),bit(n+1) {}
    int sum(int idx) {
        int res = 0;
        while(idx > 0) {
            res+=bit[idx];
            idx = idx - (idx & -idx);
        }
        return res;
    }
    void update(int idx, int x) {
        while(idx <= n) {
            bit[idx] += x;
            idx = idx + (idx & -idx);
        }
    }
};

int main(void) {
    int n; cin >> n;
    vector<int> v(n);
    BIT bit(n);
    for(int i=0;i<n;++i) cin>>v[i], bit.update(i+1, v[i]);
    int q; cin >> q;
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int idx; cin >> idx;
            cout<<bit.sum(idx)<<"\n";
        } else if(op == 2) {
            int idx, x;cin>>idx>>x;
            v[idx-1] += x;
            bit.update(idx, x);
        } else if(op == 3) {
            for(const int i:v) cout<<i<<" ";cout<<"\n";
        }
    }
}