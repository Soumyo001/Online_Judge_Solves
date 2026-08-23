#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    int ans = 0;
    while(n--) {
        int a,b,c; cin >> a >> b >> c;
        a+=b+c;
        if(a >= 2) ++ans;
    }
    cout<<ans;
}