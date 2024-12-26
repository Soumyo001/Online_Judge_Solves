#include <bits/stdc++.h>
using namespace std;
int main(void){
    vector<int> arr = {-2, 6, -3, -10, 0, 2};
    int prefix=1,suffix=1,ans = INT_MIN;
    int n = arr.size();
    for(int i=0;i<arr.size();++i){
        prefix*=arr[i];
        suffix*=arr[n-1-i];
        ans = max({ans, prefix, suffix});
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;
    }
    cout<<ans;
}