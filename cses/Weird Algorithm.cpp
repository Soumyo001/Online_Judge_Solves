#include <bits/stdc++.h>
using namespace std;

void solve(){
    long long n; cin>>n;
    while(n!=1){
        cout<<n<<" ";
        if(n & 1) n = (n * 3) + 1;
        else n/=2;
    }
    cout<<n;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    solve();
}