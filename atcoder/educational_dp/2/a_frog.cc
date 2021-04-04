#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

const int MAX_N = 1e5;
const int MAX_H = 1e4;

int N;
int h[MAX_N];

int dp[MAX_N];

int solve (void) {
  
  dp[0] = 0;
  dp[1] = abs(h[1] - h[0]);

  for (int i = 2; i < N; i++) {
    dp[i] = min(
          dp[i - 1] + abs(h[i] - h[i - 1]),
          dp[i - 2] + abs(h[i] - h[i - 2])
        );
  }

  return dp[N-1];
}

int main (void) {

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }

  int result = solve();

  cout << result << endl;

  return 0;
}
