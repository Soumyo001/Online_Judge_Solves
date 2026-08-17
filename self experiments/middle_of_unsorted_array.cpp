#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin>>v[i];

    sort(v.begin(), v.end());
    double result = 0;
    result += v[(n / 2)];
    if(n % 2 == 0) result += v[(n / 2) - 1], result /= 2;
    cout<<result;
}