#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;cin>>n;
    vector<int> p(n),q(n);
    int c = 0;
    for(int i=0;i<n;++i){
        cin>>p[i]>>q[i];
        if(q[i]-p[i] >= 2) ++c;
    }
    cout<<c;
}