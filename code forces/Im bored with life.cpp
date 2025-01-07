#include <bits/stdc++.h>
using namespace std;

int fact(int x){
    int ans = 1;
    while(x>0) ans*=x, --x;
    return ans;
}

int main(void){
    int a,b;cin>>a>>b;
    cout<<fact(min(a,b));
}