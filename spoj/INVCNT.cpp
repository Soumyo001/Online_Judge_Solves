#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll merge(int l, int mid, int r, vector<int>& arr) {
    vector<int> temp(r-l+1);
    int i=l, j=mid+1, k=0;
    ll count=0;

    while(i<=mid && j<=r) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            count += (mid-i+1);
        }
    }

    while(i<=mid) temp[k++] = arr[i++];
    while(j<=r) temp[k++] = arr[j++];
    
    for(int i=0;i<temp.size();++i) arr[l+i] = temp[i];
    return count;
}

ll mergeSort(int l, int r, vector<int>& v) {
    ll inversionCount = 0;
    if(l < r) {
        int mid = (l + r) >> 1;
        inversionCount += mergeSort(l, mid, v);
        inversionCount += mergeSort(mid+1, r, v);
        inversionCount += merge(l, mid, r, v);
    }
    return inversionCount;
}

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    cout<<mergeSort(0, n-1, v)<<"\n";
}

int main(void) {
    int t;cin>>t;
    while(t--) solve();
}