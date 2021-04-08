#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

const int MAX_N = 1e5;
const int MAX_M = 1e5;

int N, M;

vector<vector<int>> g;
vector<bool> is_start;

int dp[MAX_N];

int solve (int i) {

  if (dp[i] != -1) {
    return dp[i];
  }

  int res = 0;
  for (int j = 0; j < g[i].size(); j++) {
    res = max(res, solve(g[i][j]) + 1);
  }

  return dp[i] = res;
}

int main (void) {

  cin >> N >> M;
  g.assign(N, vector<int>());
  is_start.assign(N, true);

  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    g[x - 1].push_back(y - 1);
    is_start[y - 1] = false;
  }

  fill(dp, dp + MAX_N, -1);

  int result = 0;
  for (int i = 0; i < N; i++) {
    if (is_start[i]) {
      result = max(result, solve(i));
    }
  }

  cout << result << endl;

  return 0;
}
