#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string>& strs) {
    sort(strs.begin(), strs.end());
    string ans = "";
    string st = strs[0];
    string en = strs[strs.size()-1];
    for(int i=0,j=0;i<st.length(),j<en.length();++i,++j)
        if(st[i]==en[j]) ans+=st[i];
        else break;
    return ans;
}

int main(void){
    vector<string> s;
    string c;
    while(cin>>c) s.push_back(c);
    cout<<longestCommonPrefix(s);
}