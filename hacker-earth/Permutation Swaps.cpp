// the problem has error with test cases...
#include <iostream>
#include <vector>
int main(void){
    int t;
    std::cin>>t;
    while(t--){
        int n;
        std::cin>>n;
        std::vector<int> v(n,0);
        int sum = 0;
        bool m = false;
        for (int i = 0; i < v.size(); i++){
             std::cin>>v[i];
             sum+=v[i];
        }
        int tot = (n*(n+1))/2;
        for(auto& i:v){
            if(i<1 || i>n){
                m = true;
                break;
            }
        }
        if(sum!=tot || m==true) std::cout<<"NO\n";
        else std::cout<<"YES\n";
    }
}
