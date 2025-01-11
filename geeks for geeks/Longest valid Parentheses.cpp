#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxLength(string& s) {
        stack<int> st;
	    int mx = 0;
        for(int i=0;i<s.length();++i){
            if(s[i] == '(') st.push(i);
            else {
		        if(!st.empty()) st.pop();
                if(st.empty()) st.push(i);
            	else mx = max(mx, (i-st.top()));
            }
        }
        return mx ;
    }
};

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
