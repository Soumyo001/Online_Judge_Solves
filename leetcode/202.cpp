#include <bits/stdc++.h>
using namespace std;

bool isHappy(int n) {
    int temp = n;
    while(n != 1) {
        if(n == 4) return false;
        int sum = 0;
        while(n) {
            int d = n % 10;
            n /= 10;
            sum += (d * d);
        }
        n = sum;
    }
    return true;
}

int main(void) {
    int n; cin >> n;
    cout<< isHappy(n);
}