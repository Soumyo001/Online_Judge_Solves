#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


int bs(vector<int>& v, int key){
    int lo = 0;
    int hi = (int)v.size()-1;
    int idx = -1;
    while(lo<=hi){
        int mid = (lo+hi) >> 1;
        if(v[mid] == key) return idx=mid;
        else if(v[mid] > key) hi = mid-1;
        else lo = mid+1;
    }
    return idx;
}

int getLeftMostBs(vector<int>& v, int key){
    int lo = 0;
    int hi = v.size()-1;
    int idx = -1;
    while(lo<=hi){
        int mid = (lo+hi) >> 1;
        if(v[mid] == key){
            idx = mid;
            hi = mid - 1;
        }
        else if(v[mid] > key) hi = mid - 1;
        else lo = mid + 1;
    }
    return idx;
}

int getRightMostBs(vector<int>& v, int key){
    int lo = 0;
    int hi = v.size() - 1;
    int idx = -1;
    while(lo<=hi){
        int mid = (lo+hi) >> 1;
        if(v[mid] == key){
            idx = mid;
            lo = mid + 1;
        }
        else if(v[mid] > key) hi = mid - 1;
        else lo = mid + 1;
    }
    return idx;
}

int main(void){
    vector<int> v = {234,2,4,5,45,6,66,75,7,8,5,5,35,3,3,3,3,3,3,3,3,3,3,42,423,4,2,45,45,345,35,34,572372,7,8,578,46,8,4};
    sort(v.begin(),v.end());
    for(auto i : v) cout<<i<<" ";cout<<endl;
    int key;
    cout<<"Enter Key : ";cin>>key;
    cout<<bs(v,key)<<endl<<getLeftMostBs(v,key)<<endl<<getRightMostBs(v,key)<<endl;
}