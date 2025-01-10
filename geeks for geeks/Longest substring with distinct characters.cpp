#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        int mx = INT_MIN;
        
        for(int i=0;i<s.length();++i){
            vector<bool> vis(26, false);
            for(int j=i;j<s.length();++j){
                if(vis[s[j]-'a']) break;
                else{
                    mx = max(mx, j-i+1);
                    vis[s[j]-'a'] = true;
                }
            }
        }
        return mx;
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