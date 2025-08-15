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

ll fastExp(ll a, ll b, ll mod){
    ll ans = 1;
    while(b>0){
        if(b&1) ans = (ans * 1LL * a) % mod;
        a = (a * 1LL * a) % mod;
        b = b >> 1;
    }
    return ans;
}

void solve(){
    ll a, b, c;cin>>a>>b>>c;
    cout<<fastExp(a,fastExp(b,c,M-1),M)<<"\n";
}

int main(void){
    int t;cin>>t;
    while(t--) solve();
}