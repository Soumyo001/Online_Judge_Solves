#include <bits/stdc++.h>
#define ll long long
using namespace std;

class BIT {
private:
    int n;
    vector<ll> bit;
public:
    BIT(int n): n(n), bit(n+1) { }
    ll sum(int idx) {
        ll res = 0;
        while(idx > 0) {
            res += bit[idx];
            idx = idx - (idx & -idx);
        }
        return res;
    }
    void update(int idx, ll x) {
        while(idx <= n) {
            bit[idx] += x;
            idx = idx + (idx & -idx);
        }
    }
};

int main(void) {
    int n, q; cin >> n >> q;
    vector<ll> v(n+1);
    BIT bit(n);
    for(int i=1; i<=n; ++i) cin >> v[i], bit.update(i, v[i]);
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int k; ll u; cin >> k >> u;
            bit.update(k, u-v[k]);
            v[k] = u;
        } else if(op == 2) {
            int a, b; cin >> a >> b;
            cout << bit.sum(b) - bit.sum(a-1) << '\n';
        }
    }
}