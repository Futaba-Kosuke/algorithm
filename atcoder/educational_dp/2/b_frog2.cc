#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

const int MAX_N = 1e5;
const int MAX_H = 1e4;

int N, K;
int h[MAX_N];

ll dp[MAX_N];

ll solve (void) {
  
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);

  for (int i = 2; i < N; i++) {
    dp[i] = INF;
    for (int j = 1; i - j >= 0 && j <= K; j++) {
      dp[i] = min(
            dp[i],
            dp[i - j] + abs(h[i] - h[i - j])
          );
    }
  }

  return dp[N-1];
}

int main (void) {

  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }

  ll result = solve();

  cout << result << endl;

  return 0;
}
