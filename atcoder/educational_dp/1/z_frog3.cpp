#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
const ull INF =  1LL << 60;

ull solve (ull n, ull c, vector<ull> h) {
  vector<ull> costs(n, INF);

  costs.at(0) = 0;
  for (int i = 0; i < n; i++) {
    for (int step = 1; i + step < n; step++) {
      costs.at(i + step) = min(costs.at(i + step), costs.at(i) + (h.at(i + step) - h.at(i)) * (h.at(i + step) - h.at(i)) + c);
    }
  }

  ull result = costs.at(n-1);
  return result;
}

int main (void) {
  ull n, c;
  scanf("%llu %llu", &n, &c);

  vector<ull> h(n);
  for (int i = 0; i < n; i++) {
    scanf("%llu", &h.at(i));
  }

  ull result = solve(n, c, h);
  printf("%llu\n", result);

  return 0;
}
