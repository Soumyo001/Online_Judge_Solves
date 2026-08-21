#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    int n; cin >> n; 
    vector<ll> v(n, 0);
    for(int i = 0; i < n; ++i) cin >> v[i];
    ll currentSum = 0;
    ll mx = LLONG_MIN;
    for(const ll i : v) {
        currentSum = max(i, currentSum + i);
        mx = max(mx, currentSum);
    }
    cout<<mx<<"\n";
    return 0;
}
