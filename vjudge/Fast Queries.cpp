#include <bits/stdc++.h>
using namespace std;

struct Query {
    int l,r,idx;
};

class BIT {
private:
    int n;
    vector<int> bit;
public:
    BIT(int n): n(n), bit(n+1) { }
    void update(int idx, int x) {
        while(idx <= n) {
            bit[idx] += x;
            idx = idx + (idx & -idx);
        }
    }
    int sum(int idx) {
        int res = 0;
        while(idx > 0) {
            res += bit[idx];
            idx = idx - (idx & -idx);
        }
        return res;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> v(n+1);
    for(int i=1;i<=n;++i) cin >> v[i];
    BIT bit(n);
    vector<Query> queries;
    for(int i=0;i<q;++i) {
        int l, r; cin >> l >> r;
        queries.push_back({l,r,i});
    }
    sort(queries.begin(),queries.end(),[](const Query& a,const Query& b) { return a.r<b.r; });
    unordered_map<int,int> last,ans;
    int currR=1;
    for(const Query& q:queries) {
        while(currR <= q.r) {
            if(last.count(v[currR])) bit.update(last[v[currR]], -1);
            bit.update(currR, 1);
            last[v[currR]]=currR;
            ++currR;
        }
        ans[q.idx]=bit.sum(q.r)-bit.sum(q.l-1);
    }
    for(int i=0;i<q;++i) cout<<ans[i]<<"\n";
}

int main(void) {
    int t; cin >> t;
    for(int i=1;i<=t;++i) {
        cout<<"Case "<<i<<":\n";
        solve();
    }
}