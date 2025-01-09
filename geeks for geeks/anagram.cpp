#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool areAnagrams(string& s1, string& s2) {
        if(s1.length()!=s2.length()) return false;
        bool is = true;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        for(int i=0;i<s1.length();++i) if(s1[i]!=s2[i]) is = false;
        return is;
    }
};

int main() {

    int t = 1;

    // cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}