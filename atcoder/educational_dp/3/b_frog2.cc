#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

int N;
int K;
vector<int> h;

vector<ll> dp;

int solve (void) {
  dp[0] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 1; i + j < N && j <= K; j++) {
      dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
    }
  }

  return dp[N - 1];
}

int main (void) {
  cin >> N;
  cin >> K;
  h.assign(N, 0);
  dp.assign(N, INF);
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  int result = solve();
  cout << result << endl;
}
