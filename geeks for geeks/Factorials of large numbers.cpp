#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int n) {
    vector<int> res;
    res.push_back(1);
    for(int x=2; x<=n; ++x) {
        int carry = 0;
        for(int i=0; i<res.size(); ++i) {
            int product = res[i] * x + carry;
            res[i] = product % 10;
            carry = product / 10;
        }
        while(carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<int> factorial2(int n) {
    if(n == 0) return {1};
    vector<int> res;
    res.push_back(n); --n;
    while(n) {
        int carry = 0;
        for(int i=0; i<res.size(); ++i) {
            int product = res[i] * n + carry;
            res[i] = product % 10;
            carry = product / 10;
        }
        while(carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
        --n;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(void) {
    int n; cin >> n;
    for(const int i: factorial2(n)) cout<<i<<" ";
}