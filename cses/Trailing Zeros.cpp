#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fastExp(ll a, ll b){
    ll ans = 1;
    while(b>0){
        if(b&1) ans = ans*a;
        a = a*a;
        b>>=1;
    }
    return ans;
}

int main(void){
    ll n;cin>>n;
    ll a=5;
    ll p = 1;
    ll ans = 0;
    while(floor(n/a)>0){
        ++p;
        ans+=floor(n/a);
        a = fastExp(5,p);
    }
    cout<<ans;
}