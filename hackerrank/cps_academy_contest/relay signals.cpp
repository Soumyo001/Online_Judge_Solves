#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    int n, k; cin >> n >> k;
    vector<ll> v(n, 0);
    for(int i = 0; i < n; ++i) cin >> v[i];
    vector<ll> ans(n, 0);
    ll sum = 0;
    
    for(int i = 0; i < k; ++i) sum += v[(i + 1) % n];
    ans[0] = sum;
    
    for(int i = 1; i < n; ++i) { // 0 1 2 3 4
        sum -= v[i];
        sum += v[(i + k) % n];
        ans[i] = sum;
    }
    
    for(const ll i : ans) cout<<i<<" ";
    return 0;
}
