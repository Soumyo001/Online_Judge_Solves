#include <bits/stdc++.h>
#define ll long long
const int M = 1e9+7;
using namespace std;

ll fastMul(ll a, ll b){
    ll ans = 0;
    while(b>0){
        if(b&1) ans = (ans + a) % M;
        a = (a + a) % M;
        b = b >> 1;
    }
    return ans;
}

ll fastExp(ll a, ll b){
    ll ans = 1;
    while(b>0){
        if(b&1) ans = (ans * 1LL * a) % M;
        a = (a * 1LL * a) % M;
        b = b >> 1;
    }
    return ans;
}

void solve(){
    ll a, b;cin>>a>>b;
    cout<<fastExp(a,b)<<"\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}