#include <bits/stdc++.h>
using namespace std;
const int m = 1e9+7;

int gcd(int a, int b, int& x, int&y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int x1,y1;
    int g = gcd(b,a%b,x1,y1);
    x = y1;
    y = x1 - (a/b)*y1;
    return g;
}

void exGcd(int a, int b){
    int x, y;
    int g = gcd(a,b,x,y);
    if(g!=1) return;
    cout<<(x % m + m)%m<<"\n";
}

int main(void){
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        exGcd(b,a);
    }
}