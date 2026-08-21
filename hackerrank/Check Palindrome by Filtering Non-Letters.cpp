#include <bits/stdc++.h>
using namespace std;

bool isAlphabeticPalindrome(string code) {
    string res = "";
    for(const char c : code) if(isalpha(c)) res += tolower(c);
    code = res;
    reverse(code.begin(), code.end());
    return code == res;
}

int main()
{
    string code;
    getline(cin, code);

    bool result = isAlphabeticPalindrome(code);

    cout << result << "\n";

    return 0;
}
