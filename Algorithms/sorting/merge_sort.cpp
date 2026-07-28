#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& v, int lo, int mid, int hi) {
    int len = hi - lo + 1;
    vector<int> a(mid - lo + 1 + 1, 0);
    vector<int> b(hi - mid + 1, 0);
    for(int i = 0; i < a.size() - 1; ++i) a[i] = v[lo + i];
    for(int i = 0; i < b.size() - 1; ++i) b[i] = v[mid + 1 + i];
    a[a.size() - 1] = b[b.size() - 1] = INT_MAX;
    int i = 0, j = 0;
    for(int k = lo; k <= hi; ++k) {
        if(a[i] <= b[j]) {
            v[k] = a[i++];
        } else {
            v[k] = b[j++];
        }
    }
}

void merge_sort(vector<int>& v, int lo, int hi) {
    if(lo < hi) {
        int mid = (hi + lo) >> 1;
        merge_sort(v, lo, mid);
        merge_sort(v, mid + 1, hi);
        merge(v, lo, mid, hi);
    }
}

int main(void) {
    int n; cin >> n;
    vector<int> v(n, 0);
    for(int i=0; i<n; ++i) cin >> v[i];
    merge_sort(v, 0, n - 1);
    for(const int i : v) cout << i << " ";
    cout << "\n";
}