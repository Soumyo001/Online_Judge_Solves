#include <bits/stdc++.h>
using namespace std;

int expandFromCenter(string s, int left, int right){
    int n = s.length();
    while (left>=0 && right<n && s[left]==s[right])
    {
        --left;
        ++right;
    }
    return right - left - 1;
}

int main(void){
    string s;cin>>s;
    int start=0, end=0;
    for(int i=0;i<s.length();++i){
        int odd = expandFromCenter(s, i, i);
        int even = expandFromCenter(s, i, i+1);
        int mx = max(odd, even);
        if(mx > end-start){
            start = i - ((mx-1)/2);
            end = i + (mx/2);
        }
    }
    string m ="";
    for(int i=start;i<=end;++i) m+=s[i];
    cout<<m;
}