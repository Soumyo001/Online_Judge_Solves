#include <bits/stdc++.h>
using namespace std;

class BIT {
private:
    int n;
    vector<int> bit;
public:
    BIT(int n): n(n), bit(n+1) {}
    int sum(int idx) {
        int res = 0;
        while(idx > 0) {
            res ^= bit[idx];
            idx = idx - (idx & -idx);
        }
        return res;
    }
    void update(int idx, int x) {
        while(idx <= n) {
            bit[idx] ^= x;
            idx = idx + (idx & -idx);
        }
    }
};

int main(void) {
    int n,q; cin >> n >> q;
    BIT bit(n);
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i], bit.update(i+1, v[i]);

    while(q--) {
        int a, b; cin >> a >> b;
        cout<<(bit.sum(b) ^ bit.sum(a-1))<<"\n";
    }
}