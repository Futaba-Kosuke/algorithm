#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF =  1LL << 60;

ll solve (int n, int k, vector<int> h) {
  vector<ll> costs(n, INF);

  costs.at(0) = 0;
  for (int i = 0; i < n; i++) {
    for (int step = 1; step <= k && i + step < n; step++) {
      costs.at(i + step) = min(costs.at(i + step), costs.at(i) + abs(h.at(i + step) - h.at(i)));
    }
  }

  int result = costs.at(n-1);
  return result;
}

int main (void) {
  int n, k;
  scanf("%d %d", &n, &k);

  vector<int> h(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &h.at(i));
  }

  ll result = solve(n, k, h);
  printf("%lld\n", result);

  return 0;
}
