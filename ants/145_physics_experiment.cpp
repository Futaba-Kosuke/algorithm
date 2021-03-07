#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
const double g = 10.0;

int N, H, R, T;

double y[MAX_N];

double calc (int T) {
  if (T < 0) return H;
  double t = sqrt(2 * H / g);
  int k = (int)(T / t);
  if (k % 2 == 0) {
    double d = T - k * t;
    return H - g * d * d / 2;
  } else {
    double d = k * t + t - T;
    return H - g * d * d / 2;
  }
}

int main (void) {
  cin >> N >> H >> R >> T;
  for (int i = 0; i < N; i++) {
    y[i] = calc(T - i);    
  }
  sort(y, y + N);
  for (int i = 0; i < N; i++) {
    printf("%.2f ", y[i] + 2 * R * i / 100.0);
  }
}
