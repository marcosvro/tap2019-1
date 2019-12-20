#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
  int n, m;
  cin >> m >> n;

  m--;

  cout << (int)ceil((float)n / (float)m) << endl;

  return 0;
}