#include <bits/stdc++.h>
using namespace std;

int divisorSubstrings(int num, int k) {
    vector<int> v;
    int t = num;
    while(num) {
        v.push_back(num % 10);
        num /= 10;
    }
    reverse(v.begin(), v.end());
    int ans = 0;
    int sze = v.size();
    for(int i=0; i+k<=sze; ++i) {
        int sum = 0;
        for(int j=i; j<(i+k); ++j) sum = (sum * 10) + v[j];
        if(sum != 0 && t % sum == 0) ++ans;
    }
    return ans;
}

int main(void) {
    cout<<divisorSubstrings(430043, 2)<<"\n";
}