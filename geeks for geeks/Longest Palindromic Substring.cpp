#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    bool isPalindrome(string m, int x, int y){
        for(int i=x,j=y;i<(x+y)/2,j>=(x+y)/2;++i,--j){
            if(m[i]!=m[j]) return false;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int start = 0, stop = 0;
        int mx = INT_MIN;
        for(int i=0;i<s.length()-1;++i){
            for(int j=i+1;j<s.length();++j){
                if(isPalindrome(s,i,j)){
                    if((j-i-1)>mx){
                        mx = j-i-1;
                        start = i;
                        stop = j;
                    }
                }
            }
        }
        string m = "";
        for(int i=start;i<=stop;++i) m+=s[i];
        return m;
    }
};

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
