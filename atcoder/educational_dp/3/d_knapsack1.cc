#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

int N;
int W;

vector<pair<int, ll>> a;
vector<vector<ll>> dp;

ll solve (void) {

  // i個までにjまでの重さを選んだときの最大価値
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= W; j++) {
      if (j - a[i].first >= 0) {
        dp[i + 1][j] = max(dp[i][j], dp[i][j - a[i].first] + a[i].second);
      } else {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }

  return dp[N][W];
}

int main (void) {
  cin >> N >> W;
  a.assign(N, pair<int, ll>(0, 0));
  dp.assign(N+1, vector<ll>(W+1, 0));
  for (int i = 0; i < N; i++) {
    cin >> a[i].first >> a[i].second;
  }
  ll result = solve();
  cout << result << endl;
  return 0;
}
