#include <bits/stdc++.h>
using namespace std;

// corrent intuition: at each indenx i, is it better to extend the previous subarray or start fresh from index i

int kadane(vector<int>& v) {
    if(v.empty()) return 0;

    int currentSum = v[0];
    int maxSum = v[0];
    for(int i=1; i<v.size(); ++i) {
        currentSum = max(v[i], currentSum+v[i]);
        maxSum = max(currentSum, maxSum);
    }
    return maxSum;
}

int main(void) {
    vector<int> v = {-2, 3, -1, 2, -5};
    cout<<kadane(v)<<"\n";
}