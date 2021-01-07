#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1LL << 60;

typedef struct product {
  ll w;
  ll v;
} product;

ll solve (ll N, ll W, vector<product> products) {
  vector<vector<ll>> dp_table(N+1, vector<ll>(W+1, 0));

  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j <= W; j++) {
      if (j < products.at(i).w) {
        dp_table.at(i+1).at(j) = dp_table.at(i).at(j);
      } else {
        dp_table.at(i+1).at(j) = max(
              dp_table.at(i).at(j),
              dp_table.at(i).at(j-products.at(i).w) + products.at(i).v
            );
      }
    }
  }

  ll result = dp_table.at(N).at(W);
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
