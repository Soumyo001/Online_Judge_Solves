#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    vector<int> ans;
    for(int i=0;i<n;++i) {
        if(ans.empty() || ans[ans.size()-1]<v[i]) {
            ans.push_back(v[i]);
        } else {
            auto it = lower_bound(ans.begin(),ans.end(),v[i]);
            *it=v[i];
        }
    }
    cout<<ans.size()<<"\n";
}