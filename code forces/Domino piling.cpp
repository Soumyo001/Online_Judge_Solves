#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int m,n; cin >> m >> n;
    m *= n;
    if(m & 1) {
        cout<< ((m - 1) / 2);
    } else cout << (m / 2);
}