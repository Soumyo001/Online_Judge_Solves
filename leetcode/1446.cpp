#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s; cin>>s;
    int maxP = INT_MIN;
    char old = s[0];
    int count = 1;
    maxP = max(maxP, count);
    for(int i=1; i<s.length(); ++i) {
        if(s[i] == old) ++count;
        else {
            old = s[i];
            count = 1;
        }
        maxP = max(maxP, count);
    }
    cout<<maxP;
}