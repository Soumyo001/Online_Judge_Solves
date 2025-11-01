#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> v(n, 0);
    long long m = 0;
    for(int i=0;i<n;++i){
        cin>>v[i];
        if(i > 0 && v[i-1] > v[i]) {
            m+=(v[i-1] - v[i]);
            v[i] += (v[i-1] - v[i]);
        }
    }
    cout<<m;
}

int main(void){
    solve();
}