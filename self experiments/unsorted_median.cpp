#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin>>v[i];

    sort(v.begin(), v.end());

    int res = 0;
    res += v[int(n/2)];
    if(n % 2 == 0) {
        res += v[int(n/2) - 1];
        cout<<res/2.0<<"\n";
    } else cout << res << "\n";
    
}