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
    BIT(int n): n(n),bit(n+1, 0) { }
    void update(int idx,int x) {
        while(idx <= n) {
            bit[idx] += x;
            idx = idx + (idx & -idx);
        }
    }
    int sum(int idx) {
        int res=0;
        while(idx > 0) {
            res += bit[idx];
            idx = idx - (idx & -idx);
        }
        return res;
    }
};

int main(void) {
    int n,q; cin >> n >> q;
    vector<int> v(n+1);
    for(int i=1;i<=n;++i) cin>>v[i];
    vector<int> comp=v;
    sort(comp.begin()+1,comp.end());
    comp.erase(unique(comp.begin()+1,comp.end()),comp.end());
    for(int i=1;i<=n;++i)
        v[i]=lower_bound(comp.begin()+1,comp.end(),v[i])-comp.begin();
    BIT bit(n);
    vector<Query> queries;
    for(int i=0;i<q;++i) {
        int l,r;cin>>l>>r;
        queries.push_back({l,r,i});
    }
    sort(queries.begin(),queries.end(),[](const Query& a,const Query& b) { return a.r<b.r; });
    unordered_map<int,int> last,ans;
    for(int i=1;i<=n;++i) last[v[i]]=0;
    int curr=1;
    for(const Query& q:queries) {
        while(curr <= q.r) {
            if(last[v[curr]]!=0) bit.update(last[v[curr]], -1);
            bit.update(curr, 1);
            last[v[curr]]=curr;
            ++curr;
        }
        ans[q.idx]=bit.sum(q.r)-bit.sum(q.l-1);
    }
    for(int i=0;i<q;++i) cout<<ans[i]<<"\n";
}