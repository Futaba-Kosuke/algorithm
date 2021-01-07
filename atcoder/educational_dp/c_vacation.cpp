#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1LL << 60;

ll solve (int n, vector<vector<int>>& A) {
  vector<vector<ll>> happiness(n, vector<ll>(3, 0));

  for (int type = 0; type < 3; type++) {
    happiness.at(0).at(type) = A.at(0).at(type);
  }

  for (int i = 0; i < n - 1; i++) {
    for (int type = 0; type < 3; type++) {
      happiness.at(i+1).at(type) = max(
            happiness.at(i).at((type + 1) % 3) + A.at(i+1).at(type),
            happiness.at(i).at((type + 2) % 3) + A.at(i+1).at(type)
          );
    }
  }

  ll result = max(happiness.at(n-1).at(0), max(happiness.at(n-1).at(1), happiness.at(n-1).at(2)));
  return result;
}

int main (void) {
  int n;
  scanf("%d", &n);

  vector<vector<int>> A(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &A.at(i).at(j));
    }
  }

  ll result = solve(n, A);
  printf("%lld\n", result);

  return 0;
}
