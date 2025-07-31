#include <bits/stdc++.h>
using namespace std;

int ans(int n, vector<int>& dp){
    if(n == 0 || n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    return dp[n] = ans(n-1,dp) + ans(n-2,dp);
}

int ansTabulized(int n, vector<int>& dp){
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;++i){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int ansSpaceOptimized(int n, vector<int>& dp){
    int u = 1, v = 1;
    int curr;
    for(int i=2;i<=n;++i){
        curr = u + v;
        v = u;
        u = curr;
    }
    return u;
}

int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    dp[0]=1;
    dp[1]=1;
    return ansSpaceOptimized(n,dp);
}

int main(void){
    cout<<climbStairs(45);
}