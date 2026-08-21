#include <bits/stdc++.h>
#define ll long long
using namespace std;



int main() {
    int n; cin >> n;
    vector<ll> v(n, 0);
    for(int i = 0; i < n; ++i) cin >> v[i];
    int left = 0, right = n - 1;
    ll leftMax = LLONG_MIN, rightMax = LLONG_MIN;
    ll tot = 0;
    
    while(left < right) {
        leftMax = max(leftMax, v[left]);
        rightMax = max(rightMax, v[right]);
        if(leftMax <= rightMax) {
            tot += (leftMax - v[left]);
            ++left;
        } else {
            tot += (rightMax - v[right]);
            --right;
        }
    }
    cout<<tot<<"\n";
    
    return 0;
}
