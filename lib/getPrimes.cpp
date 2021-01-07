#include<bits/stdc++.h>

using namespace std;

vector<int> getPrimes (int N) {

  vector<bool> table(N + 1, false);
  vector<int> result(0);

  for (int num = 2; num <= N; num++) {
    if (table.at(num) == 0) {
      result.push_back(num);
      for (int i = 1; num * i <= N; i++) {
        table.at(num * i) = true;
      }
    }
  }

  return result;
  
}

int main (void) {
  int N;
  cout << "N >> ";
  cin >> N;

  vector<int> result = getPrimes(N);
  for (int i = 0; i < result.size(); i++) {
    cout << result.at(i) << endl;
  }

  return 0;
}
