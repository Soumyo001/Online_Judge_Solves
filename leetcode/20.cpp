#include <bits/stdc++.h>
using namespace std;

bool isValid(string s){
    if(s.length() == 1) return false;
    stack<int> st;
    for(int i=0;i<s.length();++i){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') st.push(s[i]);
        else if(!st.empty()){
            if((st.top() == '(' && s[i] == ')')
            || (st.top() == '{' && s[i] == '}')
            || (st.top() == '[' && s[i] == ']')
            ){
                st.pop();
            }else return false;
        }else return false;
    }
    return st.empty()? true:false;
}

int main(void){
    string s;cin>>s;
    cout<<(isValid(s)?"true":"false");
}