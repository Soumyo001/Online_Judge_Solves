#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    set<vector<int>> s;
    vector<int> v(n);
    vector<pair<int, int>> ans;
    for(int i=0; i<n; ++i) cin >> v[i];
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if(v[i] != v[j]) {
                vector<int> temp = { v[i], v[j] };
                sort(temp.begin(), temp.end());
                if(s.find(temp) == s.end()) {
                    ans.push_back({i+1, j+1});
                    s.insert(temp);
                }
            }
        }
    }
    if(ans.size() != n-1) cout<<"NO\n";
    else {
        cout<<"YES\n";
        for(auto it: ans) {
            cout<<it.first<<" "<<it.second<<"\n";
        }
    }
}

int main(void) {
    int t; cin >> t;
    while(t--) solve();
}