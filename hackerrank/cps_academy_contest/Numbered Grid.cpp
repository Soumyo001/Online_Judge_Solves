#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#define ll long long
using namespace std;


int main() {
    int n; cin >> n;
    
    ll sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += (i * n) + (i + 1);
        sum += (i * n) + (n - 1 - i) + 1; // (i*n) = base, rest = offset
    }
    
    if(n & 1) {
        ll i = n / 2;
        sum -= i * n + i + 1;
    }
    
    cout<<sum<<"\n";
    
    return 0;
}
