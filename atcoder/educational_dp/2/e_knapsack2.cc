#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

const int MAX_N = 100;
const int MAX_W = 1e9;
const int MAX_V = 1e3;

int N, W;
int w[MAX_N];
int v[MAX_N];
ll sum_v = 0;

ll dp[MAX_N + 1][MAX_N * MAX_V + 1];

ll solve (void) {

  fill(dp[0], dp[0] + MAX_N * MAX_V + 1, INF);
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= sum_v; j++) {
      if (j - v[i] >= 0) {
        dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
      } else {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }

  ll result = 0;
  for (ll j = 0; j <= sum_v; j++) {
    if (dp[N][j] <= W) {
      result = max(result, j);
    }
  }

  return result;
}

int main (void) {

  cin >> N >> W;
  for (int i = 0; i < N; i++) {
    cin >> w[i] >> v[i];
    sum_v += v[i];
  }

  ll result = solve();

  cout << result << endl;

  return 0;
}
