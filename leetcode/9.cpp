#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0) return false;
    vector<int> v;
    while(x) {
        v.push_back(x%10);
        x/=10;
    }
    for(int i: v) cout<<i<<" ";cout<<"\n";
    int half = v.size() / 2;
    for(int i=0, j=v.size()-1; i<half , j>=half; ++i, --j) {
        if(v[i] != v[j]) return false;
    }
    return true;
}

int main(void) {
    cout<<isPalindrome(101)<<"\n"<<isPalindrome(-121)<<"\n"<<isPalindrome(-2147483648)<<"\n";
}