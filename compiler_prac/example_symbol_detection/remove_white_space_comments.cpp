#include <bits/stdc++.h>

int main(void){
    std::fstream file("detected_imports.txt");

    std::string line;
    while (getline(file, line))
    {
        std::istringstream stream(line);
        std::string a, b;
        stream>>a>>b;
        std::cout<<a<<" "<<b<<"\n";
    }
        
}