#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    while (q--) {
        int i, j, k;
        cin >> i >> j >> k;
        i--; j--;
        string sub = s.substr(i, j-i+1);
        if(k==1) sort(sub.begin(), sub.end());
        else sort(sub.rbegin(), sub.rend());
        s.replace(i,j-i+1,sub);
    }

    cout << s << "\n";
}