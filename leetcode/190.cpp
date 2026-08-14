#include <bits/stdc++.h>
using namespace std;

int reverseBits(int n) {
    int rev = 0;
    int i = 0;
    while(i++ < 32) {
        rev = (rev << 1) | (n & 1);
        n >>= 1;
    }
    return rev;
}

int main(void) {
    int n; cin >> n;
    cout<<reverseBits(n);
}