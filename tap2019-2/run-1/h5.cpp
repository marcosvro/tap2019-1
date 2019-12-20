#include <bits/stdc++.h>
#include <math.h> /* ceil */
using namespace std;

int main() {
  int V, N;
  cin >> V >> N;

  cout << (int)ceil((V * N) * 0.1);
  for (int i = 2; i < 10; i++) {
    cout << " " << (int)ceil((V * N) * (i / 10.0));
  }
  cout << endl;

  return 0;
}