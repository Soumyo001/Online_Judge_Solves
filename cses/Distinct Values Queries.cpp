#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Query {
    int idx=0,l=0,r=0;
};
class BIT {
private:
    int n;
    vector<ll> bit;
public:
    BIT(int n): n(n),bit(n+1) { }
    void update(int idx,ll x) {
        while(idx <= n) {
            bit[idx] += x;
            idx = idx + (idx & -idx);
        }
    }
    ll sum(int idx) {
        ll res=0;
        while(idx > 0) {
            res += bit[idx];
            idx = idx - (idx & -idx);
        }
        return res;
    }
};

int main(void) {
    int n,q;cin>>n>>q;
    vector<ll> v(n+1);
    for(int i=1;i<=n;++i) cin>>v[i];
    BIT bit(n);
    vector<ll> comp=v;
    vector<Query> queries;
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    auto get_idx = [&](const ll val) {
        return lower_bound(comp.begin()+1,comp.end(),val)-comp.begin();
    };
    for(int i=1;i<=q;++i) {
        int l,r;cin>>l>>r;
        queries.push_back({i,l,r});
    }
    sort(queries.begin(),queries.end(),[&](const Query& a,const Query& b) { return a.r<b.r; });
    for(int i=1;i<=n;++i) {
        v[i]=get_idx(v[i]);
    }
    unordered_map<int,int> last,ans;
    int curr=1;
    for(const Query& q:queries) {
        while(curr <= q.r) {
            if(last.count(v[curr])) bit.update(last[v[curr]],-1);
            last[v[curr]] = curr;
            bit.update(last[v[curr]], 1);
            ++curr;
        }
        ans[q.idx] = bit.sum(q.r)-bit.sum(q.l-1);
    }
    for(int i=1;i<=q;++i) cout<<ans[i]<<"\n";
}