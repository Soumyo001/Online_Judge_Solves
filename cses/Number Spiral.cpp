#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll solve(ll y, ll x){
    if (y > x) {
        ll ans = (y - 1) * (y - 1);
        if (y % 2 == 1) return ans + x;
        else return y*y - x + 1;
    } else {
        ll ans = (x - 1) * (x - 1);
        if (x % 2 == 0) return ans + y;
        else return x*x - y + 1;
    }
}

// Number Spiral Value Equation:
// value(y, x) =
//   if y > x and y is odd:   (y - 1)^2 + x
//   if y > x and y is even:  y^2 - x + 1
//   if x >= y and x is even: (x - 1)^2 + y
//   if x >= y and x is odd:  x^2 - y + 1

int main(void){
    int t;cin>>t;
    while(t--) {
        ll y,x;cin>>y>>x;
        cout<<solve(y,x)<<"\n";
    }
}