#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k;

int workersNeeded(ll cap, vector<ll>& v) {
    ll load = 0;
    int workers = 1;
    for(int i = 0; i < n; ++i) {
        if(load + v[i] > cap) {
            ++workers;
            load = 0;
        }
        load += v[i];
    }
    return workers;
}

int main() {
    cin >> n >> k;
    vector<ll> v(n, 0);
    ll lo = 0, hi = 0;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        lo = max(lo, v[i]);
        hi += v[i];
    }
    
    
    while(lo < hi) {
        ll mid = (lo + hi) >> 1;
        if(workersNeeded(mid, v) <= k) hi = mid;
        else lo = mid + 1;
    }
    
    cout<<lo<<"\n";
    return 0;
}
