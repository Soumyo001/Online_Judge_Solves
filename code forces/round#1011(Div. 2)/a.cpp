#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        if (n == 1 || count(s.begin(), s.end(), s[0]) == n) {
            cout << "NO" << endl;
            continue;
        }
        if (s < string(s.rbegin(), s.rend())) {
            cout << "YES" << endl;
        } else {
            cout << (k >= 1 ? "YES" : "NO") << endl;
        }
    }

    return 0;
}
