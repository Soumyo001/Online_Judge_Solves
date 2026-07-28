#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& v, int lo, int mid, int hi) {
    vector<int> a(mid - lo + 1, 0);
    vector<int> b(hi - mid, 0);
    for(int i = 0; i < a.size(); ++i) a[i] = v[lo + i];
    for(int i = 0; i < b.size(); ++i) b[i] = v[mid + 1 + i];
    
    int i = 0, j = 0, k = lo;
    while(i < a.size() && j < b.size()) {
        if(a[i] <= b[j]) v[k++] = a[i++];
        else v[k++] = b[j++];
    }

    while(i < a.size()) v[k++] = a[i++];
    while(j < b.size()) v[k++] = b[j++];
}

void merge_sort(vector<int>& v, int lo, int hi) {
    if(lo < hi) {
        int mid = (lo + hi) >> 1;
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