#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n; cin >> n;
    int curr=0;
    int min_cap=0;
    for(int i=1;i<=n;++i) {
        int in, out; cin >> out >> in;
        curr-=out;
        curr+=in;
        min_cap = max(min_cap, curr);
    }
    cout<<min_cap<<"\n";
}