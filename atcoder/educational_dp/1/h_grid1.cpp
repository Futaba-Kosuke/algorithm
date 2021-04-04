#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;
const ll L = 1e9 + 7;

ll solve (int H, int W, vector<vector<char>> a) {
  vector<vector<ll>> dp(H+1, vector<ll>(W+1, 0));

  dp.at(1).at(1) = 1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a.at(i).at(j) != '#') {
        dp.at(i+1).at(j+1) = max(dp.at(i+1).at(j+1), dp.at(i).at(j+1) + dp.at(i+1).at(j)) % L;
      }
    }
  }

  ll result = dp.at(H).at(W);
  return result;
}

int main (void) {

  int H, W;
  cin >> H >> W;

  vector<vector<char>> a(H, vector<char>(W));

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a.at(i).at(j);
    }
  }
  

  ll result = solve(H, W, a);
  cout << result << endl;

  return 0;
}
