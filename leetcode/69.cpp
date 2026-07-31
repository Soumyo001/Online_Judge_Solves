#include <bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    double lo = 1;
    double hi = (double)x;
    double esp = 1e-9;
    while(hi - lo > esp) {
        double mid = (lo + hi) / 2;
        if(mid * mid <= x) lo = mid;
        else hi = mid;
    }
    return int(hi);
}

int main(void) {
    int n; cin >> n;
    cout<< mySqrt(n);
}