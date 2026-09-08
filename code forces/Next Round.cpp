#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int ans = 0;
    int n, k; cin >> n >> k;
    vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin >> v[i];
    for(int i=0; i < n; ++i) {
        if(v[i] > 0 && v[i] >= v[k-1]) ++ans;
    }
    cout<<ans;
}