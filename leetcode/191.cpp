#include <bits/stdc++.h>
using namespace std;

int hammingWeight(int n) {
    int ct = 0;
    while(n) {
        ct += (n & 1);
        n >>= 1;
    }
    return ct;
}

int main(void) {
    int n; cin>>n;
    cout<<hammingWeight(n);
}