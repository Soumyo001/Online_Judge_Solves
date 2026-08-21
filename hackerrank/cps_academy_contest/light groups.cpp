#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int ans = 0, sz = 0;
    
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i) cin>>v[i];
    
    for(int i = 0; i < n; ++i) {
        if(v[i] == 1) ++sz;
        else ans += sz, sz = 0;
    }
    
    cout<<ans + sz<<"\n";
     
    return 0;
}
