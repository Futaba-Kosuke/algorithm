#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

const int MAX_N = 1e5;
const int MAX_A = 1e4;

int N;
int a[MAX_N + 1][3];

ll dp[MAX_N + 1][3];

ll solve (void) {
  
  dp[0][0] = 0;
  dp[0][1] = 0;
  dp[0][2] = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 3; j++) {
      dp[i][j] = max(
          dp[i - 1][(j + 1) % 3] + a[i - 1][(j + 1) % 3],
          dp[i - 1][(j + 2) % 3] + a[i - 1][(j + 2) % 3]
        );
    }
  }

  return max(dp[N][0], max(dp[N][1], dp[N][2]));
}

int main (void) {

  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }

  ll result = solve();

  cout << result << endl;

  return 0;
}
