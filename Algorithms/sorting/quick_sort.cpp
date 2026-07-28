#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int lo, int hi) {
    int pivot = arr[hi];
    int i = lo - 1;
    for(int j=lo; j<hi; ++j) {
        if(arr[j] <= pivot) { // left most biggest number than pivot gets swapped with the latest small/equal number than pivot
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[hi]);
    return i+1;
}

void quick_sort(vector<int>& arr, int lo, int hi) {
    if(lo < hi) {
        int pi = partition(arr, lo, hi);
        quick_sort(arr, lo, pi - 1);
        quick_sort(arr, pi + 1, hi);
    }
}

int main(void) {
    int n; cin >> n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; ++i) cin>>arr[i];
    quick_sort(arr, 0, n-1);
    for(const int i : arr) cout<<i<<" ";
}