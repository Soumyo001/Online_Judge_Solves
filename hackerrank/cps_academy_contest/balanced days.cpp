#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int n; ll k;
    cin >> n >> k;
    
    unordered_map<ll, ll> count;
    count[0] = 1;

    ll prefix = 0, ans = 0;
    
    for (int i = 0; i < n; ++i) {
        ll a; cin >> a;
        prefix += a;
        auto it = count.find(prefix - k);
        if (it != count.end()) ans += it->second;

        count[prefix]++;      
    }

    cout << ans << "\n";
    return 0;
}