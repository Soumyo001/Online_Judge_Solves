#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string a, b; cin >> a >> b;
    for(int i=0; i<a.length(); ++i) a[i] = tolower(a[i]);
    for(int i=0; i<b.length(); ++i) b[i] = tolower(b[i]);
    if(a < b) cout<<1;
    else if(a > b) cout<<-1;
    else cout<<0;
}