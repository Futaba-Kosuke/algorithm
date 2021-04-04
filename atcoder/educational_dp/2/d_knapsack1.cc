#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

const int MAX_N = 100;
const int MAX_W = 1e5;
const int MAX_V = 1e9;

int N, W;
int w[MAX_N];
int v[MAX_N];

ll dp[MAX_N + 1][MAX_W + 1];

ll solve (void) {

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      if (j - w[i] >= 0) {
        dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
      } else {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }

  return dp[N][W];
}

int main (void) {

  cin >> N >> W;
  for (int i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
  }

  ll result = solve();

  cout << result << endl;

  return 0;
}
