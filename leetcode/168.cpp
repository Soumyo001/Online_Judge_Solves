#include <bits/stdc++.h>
using namespace std;

string convertToTitle(int columnNumber) {
    string res = "";
    while(columnNumber) {
        --columnNumber;
        res += ((columnNumber % 26) + 'A');
        columnNumber /= 26;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(void) {
    int n; cin >> n;
    cout<<convertToTitle(n);
}