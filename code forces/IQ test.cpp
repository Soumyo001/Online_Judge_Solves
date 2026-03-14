#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;cin>>n;
    vector<int> v(n, 0);
    int even=0, odd=0, even_pos, odd_pos;
    for(int i=0;i<n;++i){
        cin>>v[i];
        if(v[i] & 1) {
            ++odd;
            odd_pos = i+1;
        } else {
            ++even;
            even_pos = i+1;
        }
    }
    //type - 1 answer
    // cout<<(even>odd? odd_pos:even_pos);

    //type - 2 answer
    if(even == 1) cout<<even_pos<<"\n";
    else cout<<odd_pos<<"\n";
}