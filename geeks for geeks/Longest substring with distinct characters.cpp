#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int maxLen = INT_MIN;
        int l = 0;
        unordered_map<char, int> freq;
        for(int r=0; r<s.length(); ++r) {
            ++freq[s[r]];
            while(freq[s[r]] > 1) {
                --freq[s[l]];
                ++l;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};

int main() {

    int t=1;
    // cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
    }

    return 0;
}