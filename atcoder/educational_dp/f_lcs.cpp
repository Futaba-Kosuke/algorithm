#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1LL << 60;

string solve (string s, string t) {
  int n = s.length();
  int m = t.length();

  vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i] == t[j]) {
        dp.at(i+1).at(j+1) = dp.at(i).at(j) + 1;
      } else {
        dp.at(i+1).at(j+1) = max(dp.at(i).at(j+1), dp.at(i+1).at(j));
      }
    }
  }
  
  int len = dp.at(n).at(m);
  string result = "";
  int i = n;
  int j = m;
  for (;len>0;) {
    if (s[i-1] == t[j-1]) {
      result = s[i-1] + result;
      i--;
      j--;
      len--;
    } else if (dp.at(i).at(j) == dp.at(i-1).at(j)) {
      i--;
    } else {
      j--;
    }
  }
  return result;
}

int main (void) {
  string s, t;
  cin >> s;
  cin >> t;

  string result = solve(s, t);
  cout << result;

  return 0;
}
