#include <iostream>
using namespace std;

int main(void){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    int move = 0;
    for(int i=0;i<n;++i){
        int init = s[i]-'0';
        int goal = t[i]-'0';
        int fM,sM;
        fM = abs(goal-init);
        if(init > goal)
            sM = (9-init) + goal + 1;
        else
            sM = init + 1 + (9-goal);
        // cout<<init<<" "<<goal<<" "<<fM<<" "<<sM<<"\n";
        move+=min(fM,sM);
    }
    cout<<move;
}