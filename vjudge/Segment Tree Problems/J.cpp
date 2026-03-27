#include <bits/stdc++.h>
using namespace std;

class BIT {
private:
    int n;
    vector<int> bit;
public:
    BIT(int n): n(n),bit(n+1) { }
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
    int n,q;cin>>n>>q;
    vector<int> v(n+1);
    for(int i=1;i<=n;++i) cin>>v[i];
    vector<int> comp=v;
    vector<pair<char,pair<int,int>>> queries;
    for(int i=1;i<=q;++i) {
        char c;int a,b;cin>>c>>a>>b;
        queries.push_back({c,{a,b}});
        if(c == '!') comp.push_back(b);
    }
    sort(comp.begin(),comp.end());
    comp.erase(unique(comp.begin(),comp.end()),comp.end());
    auto get_index = [&](int val) {
        return lower_bound(comp.begin()+1,comp.end(),val) - comp.begin();
    };
    BIT bit(comp.size());
    for(int i=1;i<=n;++i){
        v[i]=get_index(v[i]);
        bit.update(v[i],1);
    }
    for(const auto& q:queries) {
        char type=q.first;
        int a=q.second.first;
        int b=q.second.second;
        if(type == '!') {
            bit.update(v[a], -1);
            v[a]=get_index(b);
            bit.update(v[a], 1);
        } else {
            int l = get_index(a);
            int r = upper_bound(comp.begin()+1,comp.end(),b)-comp.begin();
            cout<<bit.sum(r-1)-bit.sum(l-1)<<"\n";
        }
    }
}