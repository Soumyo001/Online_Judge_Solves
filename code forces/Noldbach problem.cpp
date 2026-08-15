#include <bits/stdc++.h>
using namespace std;

void verdict(int n, int k) {
    vector<bool> v(n + 1, true);
    v[0] = v[1] = false;
    for(int i = 2; i * i <= n; ++i) {
        if(v[i]) {
            for(int j = i * i; j <= n; j += i) v[j] = false;
        }
    }

    int ct = 0;
    vector<int> primes;
    for(int i=2; i<=n; ++i) if(v[i]) primes.push_back(i);
    
    for(int i = 0; i + 1 < primes.size(); ++i) {
        int sum = primes[i] + primes[i + 1] + 1;
        if(sum <= n && v[sum]) ++ct;
    }
    if(ct >= k) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(void) {
    int n, k; cin >> n >> k;
    verdict(n, k);
}