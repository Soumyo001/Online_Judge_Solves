#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<int> graph[N];
int n, d;
string s;

int main(void) {
  cin >> n >> d;
  cin >> s;
  int step = 0;
  int curr = 0;

  while(curr < n - 1) {
    if(curr + d < n && s[curr + d] == '1') {
      ++step;
      curr += d;
      continue;
    }
    int temp = d;
    bool found = false;
    while(temp > 0) {
      if(curr + temp < n && s[curr + temp] == '1') {
        ++step;
        curr += temp;
        found = true;
        break;
      }
      --temp;
    }
    if(!found) { step = -1; break; }
  }
  cout<<step<<"\n";
}