#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& v, int lo, int hi) {
    if(hi - lo == 0) return lo;
    int pivot = v[hi];
    int i = lo - 1;
    for(int j = lo; j < hi; ++j) {
        if(v[j] <= pivot) { // left most biggest number than pivot gets swapped with the latest small/equal number than pivot
            ++i;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[hi]);
    return i + 1;
}

void quick_sort(vector<int>& v, int lo, int hi) {
    if(lo < hi) {
        int pi = partition(v, lo, hi);
        quick_sort(v, lo, pi - 1);
        quick_sort(v, pi + 1, hi);
    }
}

int main(void) {
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin >> v[i];

    quick_sort(v, 0, n-1);
    for(int i:v) cout<<i<<" ";
    cout<<"\n";
}