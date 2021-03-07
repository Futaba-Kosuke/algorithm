#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 4000;

int n;
int A[4][MAX_N];
int CD[MAX_N * MAX_N];

int main (void) {
  cin >> n;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
    } 
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      CD[i * n + j] = A[2][i] + A[3][j];
    } 
  }

  sort(CD, CD + n * n);

  long long res = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int cd = -(A[0][i] + A[1][j]);
      res += upper_bound(CD, CD + n * n, cd) - lower_bound(CD, CD + n * n, cd);
    }
  }

  cout << res << endl;

  return 0;
}
