#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

double get_sqrt(int key){
    double lo = 0;
    double hi = key*1.f;
    while(hi-lo>0.0000000000001){
        double mid = (lo+hi) / 2.f;
        if(mid*mid >= key) hi = mid;
        else lo = mid;
    }
    return hi;
}

int main(void){
    vector<int> v = {234,2,4,5,45,6,66,75,7,8,5,5,35,3,3,3,3,3,3,3,3,3,3,42,423,4,2,45,45,345,35,34,572372,7,8,578,46,8,4};
    sort(v.begin(),v.end());
    for(auto i : v) cout<<i<<" ";cout<<endl;
    double key;
    cout<<"Enter Key : ";cin>>key;
    cout<<fixed<<setprecision(10)<<get_sqrt(key)<<endl<<sqrt(key)<<endl;
}