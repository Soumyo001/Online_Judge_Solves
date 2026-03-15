#include <bits/stdc++.h>
#define PRODUCT "product"
#define DIVIDE "divide"
#define ADD "addition"
#define SUB "subtraction"
using namespace std;

int clumsy(int n) {
    unordered_map<string, bool> m;
    m[PRODUCT] = false;
    m[DIVIDE] = false;
    m[ADD] = false;
    m[SUB] = false;
    stack<int> st;
    st.push(n);
    --n;
    while(n != 0) {
        if(!m[PRODUCT]) {
            int x = st.top(); st.pop();
            st.push(x*n);
            m[PRODUCT] = true;
        } else if (!m[DIVIDE]) {
            int x = st.top(); st.pop();
            st.push(floor(x/n));
            m[DIVIDE] = true;
        } else if(!m[ADD]) {
            st.push(n);
            m[ADD] = true;
        } else if(!m[SUB]) {
            st.push(-n);
            m[SUB] = true;
        }
        if(m[PRODUCT] && m[DIVIDE] && m[ADD] && m[SUB]) {
            m[PRODUCT] = m[DIVIDE] = m[ADD] = m[SUB] = false;
        }

        --n;
    }
    int ans = 0;
    while(!st.empty()) ans += st.top(), st.pop();
    return ans;
}

int main(void) {
    int n; cin >> n;
    cout<<clumsy(n)<<"\n";
}