#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;cin>>n;
    vector<int> v(n, 0);
    int even=0, odd=0, pos1, pos2;
    int pos;
    for(int i=0;i<n;++i) {
        cin>>v[i];
        if(v[i] % 2 !=0){
            ++odd;
            pos2 = i+1;
        }else{
            ++even;
            pos1 = i+1;
        }
    }
    cout<<(even > odd ? pos2:pos1);
}