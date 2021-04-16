#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

const int MAX_N = 2999;

int N;
vector<double> p;

double dp[MAX_N + 1][MAX_N + 1];

double solve (void) {

  // dp[i][j]: i枚目までのコインで表がj枚の確率

  dp[0][0] = 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      // 表だったのでjが1多いところに挿入
      dp[i+1][j+1] += dp[i][j] * p[i];
      // 裏だったのでj変わらないところに挿入
      dp[i+1][j] += dp[i][j] * (1 - p[i]);
    }
  }

  double result = 0;
  for (int i = N/2+1; i <= N; i++) {
    result += dp[N][i];
  }

  return result;

}

int main (void) {

  cin >> N;
  p.assign(N, 0);

  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }

  double result = solve();

  cout << fixed << setprecision(10) << result << endl;

  return 0;
}
