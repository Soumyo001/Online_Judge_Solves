#include <bits/stdc++.h>
using namespace std;

bool isAnagram(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main(void) {
    string a, b; cin >> a >>b;
    cout<<isAnagram(a, b);
}