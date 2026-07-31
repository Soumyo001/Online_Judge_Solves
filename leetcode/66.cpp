#include <bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int sze = digits.size();
    if(digits[sze - 1] < 9) {
        ++digits[sze - 1];
        return digits;
    }

    int carry = 0;
    bool add = true;
    vector<int> ans;

    for(int i = sze - 1; i>=0; --i) {
        int x = digits[i] + carry + (add ? 1:0);
        add = false;
        ans.push_back(x % 10);
        carry = x / 10;
    }
    if(carry) ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(void) {
    int n; cin>>n;
    vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin>>v[i];
    for(const int i: plusOne(v)) cout<<i;
}