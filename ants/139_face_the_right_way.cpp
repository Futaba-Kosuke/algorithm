#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 5000;

int N;
int cows[MAX_N];

int calc (int K) {
  int is_reverse[MAX_N] = {0};
  int res = 0;
  int sum = 0;
  
  for (int i = 0; i + K <= N; i++) {
    if ((cows[i] + sum) % 2 != 0) {
      res++;
      is_reverse[i] = 1;
    }
    sum += is_reverse[i];
    if (i - K + 1 >= 0) {
      sum -= is_reverse[i - K + 1];
    }
  }

  for (int i = N - K + 1; i < N; i++) {
    if ((cows[i] + sum) % 2 != 0) {
      return -1;
    }
    if (i - K + 1 >= 0) {
      sum -= is_reverse[i - K + 1];
    }
  }

  return res;
} 

int main (void) {

  scanf("%d%*c", &N);
  for (int i = 0; i < N; i++) {
    char c;
    scanf("%c", &c); 
    if (c == 'F') {
      cows[i] = 0;
    } else {
      cows[i] = 1;
    }
  }

  // 最も入れ替え回数の多い組み合わせで初期化
  int K = 1;
  int M = N;

  for (int k = 1; k <= N; k++) {
    int m = calc(k);
    if (m < M && m >= 0) {
      M = m;
      K = k;
    }
  }

  cout << M << " " << K << endl;

  return 0;
}
