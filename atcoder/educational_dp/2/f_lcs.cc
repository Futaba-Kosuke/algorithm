#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

const int MAX_STRING = 3000;

string s, t;

ll dp[MAX_STRING + 1][MAX_STRING + 1];

string solve (void) {

  string result = "";

  for (int i = 0; i < s.length(); i++) {
    for (int j = 0; j < t.length(); j++) {
      if (s[i] == t[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }

  int i = s.length() - 1;
  int j = t.length() - 1;
  while (i >= 0 && j >= 0) {
    if (dp[i + 1][j + 1] == dp[i + 1][j]) {
      j--;
    } else if (dp[i + 1][j + 1] == dp[i][j + 1]) {
      i--;
    } else {
      result = s[i] + result;
      i--;
      j--;
    }
  }

  return result;

}

int main (void) {

  cin >> s >> t;

  string result = solve();

  cout << result << endl;

  return 0;
}
