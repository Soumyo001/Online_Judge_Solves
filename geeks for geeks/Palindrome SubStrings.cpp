#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  bool isPalindrome(string s, int x, int y){
    for(int i=x,j=y;i<(x+y)/2,j>=(x+y)/2;++i,--j) if(s[i]!=s[j]) return false;
    return true;
}
    int CountPs(string &s) {
            int c = 0;
    for(int i=0;i<s.length();++i){
        for(int j=i;j<s.length();++j){
            if(isPalindrome(s,i,j)) if(j-i+1 >= 2) ++c;
        }
    }
    return c;
    }
};

int main() {
    int t=1;
    // cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.CountPs(s) << endl;
    }
    return 0;
}