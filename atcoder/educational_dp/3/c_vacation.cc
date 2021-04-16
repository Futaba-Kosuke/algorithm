#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

int N;

vector<vector<int>> a;
vector<vector<int>> dp;

int solve (void) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i + 1][j] = max(dp[i][(j + 1) % 3] + a[i][(j + 1) % 3], dp[i][(j + 2) % 3] + a[i][(j + 2) % 3]);
    }
  }

  int result = max(dp[N][0], max(dp[N][1], dp[N][2]));

  return result;
}

int main (void) {
  cin >> N;
  a.assign(N, vector<int>(3, 0));
  dp.assign(N+1, vector<int>(3, 0));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  int result = solve();
  cout << result << endl;
  return 0;
}
