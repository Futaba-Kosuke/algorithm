#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

const int MAX_V = 1e3;

int N;
int W;

ll sum_v = 0;

vector<pair<int, ll>> a;
vector<vector<ll>> dp;

ll solve (void) {

  // i個までに価値jになるように選んだときの最小重さ
  dp[0][0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= sum_v; j++) {
      if (j - a[i].second >= 0) {
        dp[i + 1][j] = min(dp[i][j], dp[i][j - a[i].second] + a[i].first);
      } else {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }

  ll result = 0;
  for (int j = 0; j <= sum_v; j++) {
    if (dp[N][j] <= W) {
      result = j;
    }
  }

  return result;
}

int main (void) {
  cin >> N >> W;
  a.assign(N, pair<int, ll>(0, 0));
  dp.assign(N+1, vector<ll>(MAX_V * N, INF));
  for (int i = 0; i < N; i++) {
    cin >> a[i].first >> a[i].second;
    sum_v += a[i].second;
  }
  ll result = solve();
  cout << result << endl;
  return 0;
}
