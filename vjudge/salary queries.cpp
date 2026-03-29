#include <bits/stdc++.h>
#define ll long long
using namespace std;

class BIT {
private:
    int n;
    vector<int> bit;
public:
    BIT(int n): n(n),bit(n+1, 0) { }
    void update(int idx,int x) {
        while(idx <= n) {
            bit[idx]+=x;
            idx = idx + (idx & -idx);
        }
    }
    ll sum(int idx) {
        ll res=0;
        while(idx > 0) {
            res+=bit[idx];
            idx = idx - (idx & -idx);
        }
        return res;
    }
};

int main(void) {
    int n,q;cin>>n>>q;
    vector<ll> v(n+1);
    for(int i=1;i<=n;++i) cin>>v[i];
    vector<ll> comp=v;
    vector<pair<char,pair<ll,ll>>> queries;
    for(int i=1;i<=q;++i) {
        char type;ll a,b;cin>>type>>a>>b;
        queries.push_back({type,{a,b}});
        if(type == '!') comp.push_back(b);
    }
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    auto get_idx = [&](const ll val) {
        return lower_bound(comp.begin()+1,comp.end(),val)-comp.begin();
    };
    BIT bit(comp.size());
    for(int i=1;i<=n;++i) {
        v[i] = get_idx(v[i]);
        bit.update(v[i], 1);
    }
    for(const auto& q:queries) {
        char type=q.first;
        ll a=q.second.first;
        ll b=q.second.second;
        if(type == '!') {
            bit.update(v[a],-1);
            v[a]=get_idx(b);
            bit.update(v[a],1);
        } else {
            int l=get_idx(a);
            int r=upper_bound(comp.begin()+1,comp.end(),b)-comp.begin();
            cout<<bit.sum(r-1)-bit.sum(l-1)<<"\n";
        }
    }
}