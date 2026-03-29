#include <bits/stdc++.h>
using namespace std;

struct Query {
    int idx=0,l=0,r=0;
};
class BIT {
private:
    int n;
    vector<int> bit;
public:
    BIT(int n): n(n),bit(n+1) { }
    void update(int idx, int val) {
        while(idx <= n) {
            bit[idx]+=val;
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

int main(void) {
    int n,q;cin>>n>>q;
    vector<int> v(n+1);
    BIT bit(n);
    for(int i=1;i<=n;++i) cin>>v[i];
    vector<int> comp=v;
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    for(int i=1;i<=n;++i) 
        v[i] = lower_bound(comp.begin()+1,comp.end(),v[i])-v.begin();
    vector<Query> queries;
    for(int i=0;i<q;++i) {
        int l,r;cin>>l>>r;
        queries.push_back({i,l,r});
    }
    unordered_map<int,int> ans,last_seen;
    for(int i=1;i<=n;++i) last_seen[v[i]]=-1;
    sort(queries.begin(),queries.end(),[&](const Query& a,const Query& b) { return a.r<b.r; });
    int curr=1;
    for(const Query& q:queries) {
        while(curr <= q.r) {
            if(last_seen[v[curr]]!=-1) bit.update(last_seen[v[curr]],-1);
            bit.update(curr,1);
            last_seen[v[curr]]=curr;
            ++curr;
        }
        ans[q.idx]=bit.sum(q.r)-bit.sum(q.l-1);
    }
    for(int i=0;i<q;++i) cout<<ans[i]<<"\n";
}