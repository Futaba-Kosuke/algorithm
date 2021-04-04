#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

double solve (int N, vector<double> a) {
  vector<vector<double>> dp(N+1, vector<double>(N+1, 0));

  dp.at(0).at(0) = 1;
  for (int i = 1; i < N + 1; i++) {
    for (int j = 0; j < i + 1; j++) {
      if (j > 0) {
        dp.at(i).at(j) = dp.at(i-1).at(j) * (1-p.at(i)) + dp.at(i-1).at(j-1) * p.at(i);
      } else {
        dp.at(i).at(j) = dp.at(i-1).at(j) * (1-p.at(i));
      }
    }
  }

  double result = 0;
  for (int j = N/2+1; j < N + 1; j++) {
    result += dp[N][j];
  }

  return result;
}

int main (void) {

  int N;
  cin >> N;

  vector<double> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  
  double result = solve(N, a);
  printf("%.10lf\n", result);

  return 0;
}
