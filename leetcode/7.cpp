#include <bits/stdc++.h>
using namespace std;

int reverse(int x) {
    if(!x) return x;
    int ans = 0;

    while(x != 0) {
        int n = x % 10;
        x = x / 10;
        if (ans > INT_MAX / 10 || ans < INT_MIN / 10) return 0;
        ans = (ans * 10) + n;
    }
    return ans;
}

int main(void){
    int n;cin>>n;
    cout<<reverse(n)<<"\n";
}