#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(void) {
    int n;cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;++i) cin>>v[i];
    stack<int> st;
    ll currHeight=-1;
    ll ans=LLONG_MIN;
    for(int i=0;i<=n;++i) {
        while(!st.empty() && v[st.top()] > (i==n?0:v[i])) {
            currHeight = v[st.top()];
            st.pop();
            int width=0;
            if(st.empty()) width=i;
            else width=i-st.top()-1;
            ans=max(ans,currHeight*width);
        }
        st.push(i);
    }
    cout<<ans<<"\n";
}