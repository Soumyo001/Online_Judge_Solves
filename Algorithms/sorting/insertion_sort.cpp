#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int>& arr) {
    for(int i = 1; i < arr.size(); ++i) {
        int curr = arr[i];
        int prev = i - 1;
        while(prev >= 0 && arr[prev] > curr) {
            arr[prev + 1] = arr[prev];
            --prev;
        }
        arr[prev + 1] = curr;
    }
}

int main(void) {
    int n; cin >> n;
    vector<int> arr(n, 0);
    for(int i=0;i<n;++i) cin>>arr[i];
    insertion_sort(arr);
    for(const int i : arr) cout<<i<<" ";
    cout<<'\n';
}