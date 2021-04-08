#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

const int MAX_H = 1000;
const int MAX_W = 1000;

int H, W;

ll dp[MAX_H + 1][MAX_W + 1];

ll solve (void) {

  dp[1][1] = 1;

  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {

      if (i == 1 && j == 1) continue;
      if (dp[i][j] == -1) {
        dp[i][j] = 0;
        continue;
      }

      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % (ll)(1e9 + 7);

    }
  }

  return dp[H][W];

}

int main (void) {

  cin >> H >> W;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      char a;
      cin >> a;
      
      if (a == '#') {
        dp[i][j] = -1;
      } else {
        dp[i][j] = 0;
      }
    }
  }

  ll result = solve();

  cout << result << endl;

  return 0;
}
