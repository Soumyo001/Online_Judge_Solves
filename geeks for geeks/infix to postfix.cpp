#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    string infixToPostfix(string& s) {
        auto f = [](char c){
            if(c=='^') return 3;
            else if(c=='*' || c=='/') return 2;
            else if(c=='+' || c=='-') return 1;
            else return -1;
        };
        stack<char> st;
        string res = "";
        for(int i=0;i<s.length();++i){
            if(isalnum(s[i])) res+=s[i];
            else if(s[i]=='(') st.push(s[i]);
            else if(s[i]==')'){
                while(!st.empty() && st.top()!='(') res+=st.top(),st.pop();
                st.pop();
            }else{
                while(!st.empty() && f(st.top())>=f(s[i])) res+=st.top(),st.pop();
                st.push(s[i]);
            }
        }
        while(!st.empty()) res+=st.top(),st.pop();
        return res;
    }
};

int main() {
    int t=1;
    // cin >> t;
    // cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}