#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> m;
    int left = 0;
    int mx = 0;
    for(int right = 0; right < s.length(); ++right) {
        ++m[s[right]];
        while(m[s[right]] > 1) {
            --m[s[left]];
            ++left;
        }
        mx = max(mx, right - left + 1);
    }
    return mx;
}

int main(void){
    string s;
    cin>>s;
    cout<<lengthOfLongestSubstring(s)<<"\n";
}