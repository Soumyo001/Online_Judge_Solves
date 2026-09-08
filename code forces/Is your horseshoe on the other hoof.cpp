#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int solve() {
    vector<ll> v(4, 0);
    int ans = 0;
    unordered_map<ll, int> m;
    for(int i=0; i<4; ++i) cin>>v[i], ++m[v[i]];
    for(int i=0; i<4; ++i) if(m[v[i]] > 1) ans += (m[v[i]] - 1), m[v[i]] = 0;
    return ans;
}
 
int main(void) {
    cout<<solve();
}