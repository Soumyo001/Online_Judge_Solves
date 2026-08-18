#include <bits/stdc++.h>
using namespace std;

int countValidWords(string sentence) {
    stringstream ss(sentence);
    string word;
    int ct = 0;
    while(ss >> word) {
        bool valid = true;
        int h = 0, p = 0;
        for(int i = 0; i < word.length(); ++i) {
            if((word[i] == ',' || word[i] == '!' || word[i] == '.')) {
                ++p;
                if(i != word.length() - 1 || p > 1) {
                    valid = false; 
                    break;
                }
            }  
            else if(word[i] == '-') {
                ++h;
                if(i == 0 || i == word.length() - 1 || h > 1 || !islower(word[i-1]) || !islower(word[i+1])) {
                    valid = false; 
                    break;
                }
            }
            else if(isdigit(word[i])) {
                valid = false; 
                break;
            }
        }
        if(valid) ++ct;
    }
    return ct;
}

int main(void) {
    string s; getline(cin, s);
    cout<<countValidWords(s);
}