#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    if(n == 0 || n == 1) return 0;
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i * i < n; ++i) {
        if(isPrime[i]) {
            for(int j = i * i; j < n; j += i) isPrime[j] = false;
        }
    }

    int ct = 0;
    for(int i=2; i< n; ++i) if(isPrime[i]) ++ct;
    return ct;
}

int main(void) {
    int n; cin >> n; cout << countPrimes(n);
}