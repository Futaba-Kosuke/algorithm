#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1LL << 60;
const int MAX_V = 100001;

typedef struct product {
  ll w;
  ll v;
} product;

ll solve (ll N, ll W, vector<product> products) {
  vector<vector<ll>> dp_table(N+1, vector<ll>(MAX_V, INF));

  ll result = 0;

  dp_table.at(0).at(0) = 0;
  for (ll i = 0; i < N; i++) {
    for (ll v = 0; v < MAX_V; v++) {
      if (v < products.at(i).v) {
        dp_table.at(i+1).at(v) = dp_table.at(i).at(v);
      } else {
        dp_table.at(i+1).at(v) = min(
              dp_table.at(i).at(v),
              dp_table.at(i).at(v-products.at(i).v) + products.at(i).w
            );
      }
    }
  }

  for (ll v = 0; v < MAX_V; v++) {
    if (dp_table.at(N).at(v) <= W) {
      result = v;
    }
  }

  return result;

}

int main (void) {
  ll N, W;
  scanf("%lld %lld", &N, &W);

  vector<product> products(N);
  for (ll i = 0; i < N; i++) {
    scanf("%lld %lld", &products.at(i).w, &products.at(i).v);
  }

  ll result = solve(N, W, products);
  printf("%lld\n", result);

  return 0;
}
