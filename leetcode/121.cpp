#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.empty()) return 0;

    int buy = prices[0];
    int profit = prices[0] - buy;
    for(const int i: prices) {
        if(i < buy) buy = i;
        else if(i - buy > profit) profit = i - buy;
    }
    return profit;
}

int main(void) {
    int n; cin >> n;
    vector<int> prices(n);
    for(int i=0;i<n;++i) cin>>prices[i];
    cout<<maxProfit(prices)<<"\n";
}