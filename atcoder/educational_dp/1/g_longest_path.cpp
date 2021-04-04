#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1LL << 60;
const int N_MAX = 1e5;
const int M_MAX = 1e5;

int dp[N_MAX] = { 0 };
int paths[N_MAX][M_MAX] = { INT_MAX };

int rec (int M, int x) {
  if (dp[x] != -1) {
    return dp[x];
  }

  int result = 0;
  for (int i = 0; paths[x][i] != INT_MAX; i++) {
    result = max(result, rec(M, paths[x][i]) + 1);
  }

  return dp[x] = result;
}

int solve (int N, int M) {

  int result = 0;

  for (int i = 0; i < N; i++) {
    result = max(result, rec(M, i));
  }

  return result;
}


int main (void) {
  int N, M;
  cin >> N >> M;

  int x, y;
  for (int i = 0; i < M; i++) {
    cin >> x >> y;
    for (int j = 0; j < M; j++) {
      if (paths[x][j] == INT_MAX) {
        paths[x][j] = y;
        break;
      }
    }
  }

  int result = solve(N, M);
  cout << result << endl;

  return 0;
}
